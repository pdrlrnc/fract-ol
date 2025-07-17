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

SRC_FILES	= main parser factories fractals comp_math render events handlers parser2
FT_PRINTF	= ft_printf
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include
NAME		= fractol
MINILIBX_URL	= https://github.com/42paris/minilibx-linux
CLONE_DIR	= minilibx-linux

CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)
LDFLAGS		= -L$(FT_PRINTF) -lftprintf -L$(CLONE_DIR) -lmlx -lXext -lm -lbsd -lX11

SRC			= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) minilibx
	@$(CC) -g $(CFLAGS) -I$(CLONE_DIR) -c $< -o $@


$(NAME): $(OBJ)
	@make -s -C $(FT_PRINTF)
	@$(CC) -g $(CFLAGS) $(OBJ) \
	     -L$(FT_PRINTF) -lftprintf \
	     -L$(CLONE_DIR) -lmlx -lXext -lm -lbsd -lX11 \
	     -o $(NAME)
clean:
	@$(RM) $(OBJ_DIR)
	@make clean -s -C $(FT_PRINTF)
	@make clean -s -C $(CLONE_DIR)

fclean: clean
	@$(RM) $(CLONE_DIR)
	@$(RM) $(NAME) libft.a
	@make fclean -s -C $(FT_PRINTF)

$(CLONE_DIR):
	@git clone --depth 1 $(MINILIBX_URL) $(CLONE_DIR)

minilibx: $(CLONE_DIR)
	@make -s -C $(CLONE_DIR)

re: fclean all

.PHONY: all clean fclean re minilibx
