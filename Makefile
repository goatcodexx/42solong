# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/06 19:44:42 by sywee             #+#    #+#              #
#    Updated: 2026/10/06 22:16:18 by sywee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= so_long

CC      	= cc
CFLAGS		= -Wall -Wextra -Werror -Iinclude

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

# *** MLX flags and includes for Linux ***
MLX_DIR 	= minilibx
MLX			= $(MLX_DIR)/libmlx.a
MLXFLAGS 	= -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

SRCS    	= main.c
OBJS    	= $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

# *** Link the executable using MLXFLAGS ***
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

# Compile object files
%.o: %.c include/so_long.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

# Remove object files
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS)

# Remove library and executable
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) test

# Rebuild everything
re: fclean all