# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:15:24 by eguelin           #+#    #+#              #
#    Updated: 2023/04/16 19:40:00 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Standard
OUT_DIR	= build/
SRC_DIR	= src/
INC_DIR	= include/
LIB_DIR	= lib/
NAME	= fdf
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I $(INC_DIR) -O3 #-fsanitize=address -g3
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
ALL_FILES = image.c main.c parsing.c projection.c tool.c

MYLIB_DIR = mylib/
FILES_MYLIB = mylib.a
LIB_FILES = $(addprefix $(MYLIB_DIR), $(FILES_MYLIB))

INC_FILES	= fdf.h

OBJS		= $(addprefix $(OUT_DIR), $(ALL_FILES:.c=.o))
HEADERS		= $(addprefix $(INC_DIR), $(INC_FILES))
LIB			= $(addprefix $(LIB_DIR), $(LIB_FILES))

#Sources bonus
BNS_DIR	= bonus/
BNS_FILES	= camera_bonus.c color_bonus.c hook_bonus.c image_bonus.c main_bonus.c parsing_bonus.c projection_bonus.c rgb_bonus.c tool_bonus.c
ALL_BNS_FILES	= $(addprefix $(BNS_DIR), $(BNS_FILES))

BNS_INC_FILES	= fdf_bonus.h

BNS_OBJS	= $(addprefix $(OUT_DIR), $(ALL_BNS_FILES:.c=.o))
BNS_HEADERS	= $(addprefix $(INC_DIR), $(BNS_INC_FILES))

#Rules
all: $(NAME)

$(NAME): $(OUT_DIR) $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) -o $(NAME)
	@echo $(COMP_MSG)
	@norminette $(INC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'
	@norminette $(SRC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(OUT_DIR)%.o : $(SRC_DIR)%.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OUT_DIR) $(BNS_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(BNS_OBJS) $(LIB) $(MLX) -o $(NAME)
	@echo $(COMP_BNS_MSG)
	@norminette $(INC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'
	@norminette $(SRC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(OUT_DIR)%.o : $(SRC_DIR)%.c Makefile $(BNS_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./lib/mylib
	$(RM) $(OUT_DIR)
	@echo $(CLEAN_MSG)

fclean:
	$(MAKE) fclean -C ./lib/mylib
	$(RM) $(NAME) $(OUT_DIR)
	@echo $(CLEAN_MSG)
	@echo $(FULL_CLEAN_MSG)

force:

$(LIB): force
	$(MAKE) -C ./lib/mylib
	$(MAKE) -C ./lib/minilibx-linux

$(OUT_DIR): force
	mkdir -p $(shell find $(SRC_DIR) -type d | awk -F "$(SRC_DIR)" '$$NF!="$(SRC_DIR)" {print "$(OUT_DIR)"$$(NF)}')

re: fclean all

.PHONY: all bonus clean fclean force re
#.SILENT:
