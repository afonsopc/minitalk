NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_SRC = libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_strlen.c libft/ft_error.c
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
LIBFT_LIB = lib/libft.a

all: $(NAME)
$(NAME): $(LIBFT_LIB) server client

$(LIBFT_LIB): $(LIBFT_OBJ)
	ar rcs $(LIBFT_LIB) $(LIBFT_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server:
	$(CC) $(CFLAGS) server.c $(LIBFT_LIB) -o server

client:
	$(CC) $(CFLAGS) client.c $(LIBFT_LIB) -o client

clean:
	rm -f $(LIBFT_OBJ)

fclean: clean
	rm -f server client $(LIBFT_LIB)

re: fclean all
