# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emilien <emilien@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:15:24 by eguelin           #+#    #+#              #
#    Updated: 2023/03/03 00:32:35 by emilien          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Standard
OUT_DIR	= build
SRC_DIR	= src
INC_DIR	= include
LIB_DIR	= lib
NAME	= fdf
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I $(INC_DIR)/ -fsanitize=address -g3
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
FILES		= $(shell find $(SRC_DIR) -type f | awk -F "." '$$NF=="c" {print $$0}' | awk -F "$(SRC_DIR)" '{print $$NF}')
OBJS		= $(addprefix $(OUT_DIR), $(FILES:.c=.o))
HEADERS		= $(shell find $(INC_DIR) -type f | awk -F "." '$$NF=="h" {print $$0}')
LIB			= $(shell find $(LIB_DIR)/mylib -type f | awk -F "." '$$NF=="a" {print $$0}')

#Rules
.PHONY: all
all: $(NAME)

$(NAME): $(OUT_DIR) $(OBJS) | lib
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) -o $(NAME)
	echo $(COMP_MSG)
	norminette $(INC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'
	norminette $(SRC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(OUT_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) clean -sC ./lib/minilibx-linux
	$(MAKE) clean -sC ./lib/mylib
	$(RM) $(OUT_DIR)
	echo $(CLEAN_MSG)

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -sC ./lib/mylib
	$(RM) $(NAME)
	echo $(FULL_CLEAN_MSG)

.PHONY: re
re: fclean all

.PHONY: lib
lib:
	$(MAKE) -sC ./lib/minilibx-linux
	$(MAKE) -sC ./lib/mylib

$(OUT_DIR):
	mkdir -p $(shell find $(SRC_DIR) -type d | awk -F "$(SRC_DIR)" '$$NF!="$(SRC_DIR)" {print "$(OUT_DIR)"$$(NF)}')

.SILENT:
