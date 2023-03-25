# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:15:24 by eguelin           #+#    #+#              #
#    Updated: 2023/03/25 17:08:35 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Standard
OUT_DIR	= build/
SRC_DIR	= src/
INC_DIR	= include/
LIB_DIR	= lib/
NAME	= fdf
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I $(INC_DIR) -O3 -fsanitize=address -g3
MLX		= -Lmlx_linux -lmlx_Linux -L ./lib/minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz
RM		= rm -rf
ARC		= ar rcs

#Colors
BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m

#Sentence
COMP_MSG		= "$(GREEN)Compilation $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
CLEAN_MSG		= "$(RED)Cleaning $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
FULL_CLEAN_MSG	= "$(PURPLE)Full cleaning $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"

#Sources
ALL_FILES = camera.c color.c hook.c image.c main.c parsing.c projection.c rgb.c tool.c

MYLIB_DIR = mylib/
FILES_MYLIB = mylib.a
LIB_FILES = $(addprefix $(MYLIB_DIR), $(FILES_MYLIB))

INC_FILES	= fdf.h

OBJS		= $(addprefix $(OUT_DIR), $(ALL_FILES:.c=.o))
HEADERS		= $(addprefix $(INC_DIR), $(INC_FILES))
LIB			= $(addprefix $(LIB_DIR), $(LIB_FILES))

#Rules
.PHONY: all
all: $(NAME)

$(NAME): $(OUT_DIR) $(OBJS) | lib
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) -o $(NAME)
	@echo $(COMP_MSG)
	@norminette $(INC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'
	@norminette $(SRC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(OUT_DIR)%.o : $(SRC_DIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) clean -C ./lib/minilibx-linux
	$(MAKE) clean -C ./lib/mylib
	$(RM) $(OUT_DIR)
	@echo $(CLEAN_MSG)

.PHONY: fclean
fclean:
	$(MAKE) clean -C ./lib/minilibx-linux
	$(MAKE) fclean -C ./lib/mylib
	$(RM) $(NAME) $(OUT_DIR)
	@echo $(CLEAN_MSG)
	@echo $(FULL_CLEAN_MSG)

.PHONY: re
re: fclean all

.PHONY: lib
lib:
	$(MAKE) -C ./lib/minilibx-linux
	$(MAKE) -C ./lib/mylib

$(OUT_DIR):
	mkdir -p $(shell find $(SRC_DIR) -type d | awk -F "$(SRC_DIR)" '{print "$(OUT_DIR)"$$(NF)}')

.PHONY: all clean fclean re
#.SILENT:
