NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRCS    = ft_printf.c ft_printf_utils.c ft_putstr.c ft_putchar.c ft_putnbr.c ft_puthex.c
OBJS    = $(SRCS:.c=.o)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Create the test executable
test: $(NAME)
	$(CC) test.c -L. -lftprintf -o test
	valgrind ./test

# Default target
all: $(NAME)

# Remove object files
clean:
	rm -f $(OBJS)

# Remove library and executable
fclean: clean
	rm -f $(NAME) test

# Rebuild everything
re: fclean all

.PHONY: test