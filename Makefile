# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cpost <cpost@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/20 11:27:58 by cpost         #+#    #+#                  #
#    Updated: 2022/07/01 11:45:25 by cpost         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./lib/MLX42/include/ ./lib/libft/include/ ./lib/printf/include/ ./lib/getnextline/include/

LIBMLX_PATH = ./lib/MLX42/
LIBFT_PATH = ./lib/libft/
LIBPRINTF_PATH = ./lib/printf/
LIB_GETNEXTLINE_PATH = ./lib/getnextline/

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_NAME = $(shell ls $(SRC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)
LIBMLX_NAME = libmlx42.a
LIBFT_NAME = libft.a
LIBFTPRINT_NAME = printf.a
GETNEXTLINE_NAME = getnextline.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBMLX_PATH)$(LIBMLX_NAME) $(LIBFT_PATH)$(LIBFT_NAME) $(LIBPRINTF_PATH)$(LIBFTPRINT_NAME) $(LIB_GETNEXTLINE_PATH)$(GETNEXTLINE_NAME)

BOLD = \033[1m
GREEN = \033[32;1m
RED	= \033[31;1m
YELLOW	= \033[33;1m
RESET = \033[0m

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBMLX_PATH)
	@make -C $(LIBFT_PATH)
	@make -C $(LIBPRINTF_PATH)
	@make -C $(LIB_GETNEXTLINE_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(INC) $(OBJ) -o $(NAME) && printf "$(YELLOW)$(BOLD)\rBuilt $(NAME)\r\e[35C[OK]\n$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

cleanlib:
	@make -C $(LIBMLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@make -C $(LIBPRINTF_PATH) clean
	@make -C $(LIB_GETNEXTLINE_PATH) clean

fcleanlib:
	@make -C $(LIBMLX_PATH) fclean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(LIBPRINTF_PATH) fclean
	@make -C $(LIB_GETNEXTLINE_PATH) fclean

clean: cleanlib
	@echo "$(RED)Cleaning$(RESET)"
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean fcleanlib
	@rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all