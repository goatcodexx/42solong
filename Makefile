# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/06 19:44:42 by sywee             #+#    #+#              #
#    Updated: 2026/10/06 19:44:43 by sywee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

MLX_DIR = ./minilibx

SRCS    = main.c
OBJS    = $(SRCS:.c=.o)

# *** MLX flags and includes for Linux ***
MLXFLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
INCLUDES = -I$(MLX_DIR)

all: $(NAME)

# *** Link the executable using MLXFLAGS ***
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJS)

# Remove library and executable
fclean: clean
	rm -f $(NAME) test

# Rebuild everything
re: fclean all