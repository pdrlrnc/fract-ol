# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 11:23:31 by pedde-so          #+#    #+#              #
#    Updated: 2025/07/07 11:23:33 by pedde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= main parser factories mandlebrot render events
FT_PRINTF	= ft_printf
MINILIBX	= minilibx-linux
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include
NAME		= fractol

CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)
LDFLAGS		= -L$(FT_PRINTF) -lftprintf -L$(MINILIBX) -lmlx -lXext -lm -lbsd -lX11

SRC			= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -g $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJ)
	@make -s -C $(FT_PRINTF)
	@make bonus -s -C $(FT_PRINTF)
	@make -s -C $(MINILIBX)
	@$(CC) -g $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -s -C $(FT_PRINTF)
	@make clean -s -C $(MINILIBX)

fclean: clean
	@$(RM) $(NAME) libft.a
	@make fclean -s -C $(FT_PRINTF)
	@make clean -s -C $(MINILIBX)

re: fclean all

.PHONY: all clean fclean re
