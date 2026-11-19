# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/06 19:44:42 by sywee             #+#    #+#              #
#    Updated: 2026/11/02 16:26:29 by sywee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= so_long

CC      	= cc
CFLAGS		= -Wall -Wextra -Werror -Iinclude -Iminilibx -Ilibft -Ift_printf -Iget_next_line

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

# *** MLX flags and includes for Linux ***
MLX_DIR 	= minilibx
MLX			= $(MLX_DIR)/libmlx.a
MLXFLAGS 	= -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

SRCS    	= src/so_long.c src/error.c src/arg_check.c libft/get_next_line.c
OBJS    	= $(SRCS:.c=.o)

all: $(NAME)

# *** Link the executable using MLXFLAGS ***
$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

# Compile object files
%.o: %.c include/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

# Remove library and executable
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re