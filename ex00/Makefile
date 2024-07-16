NAME=megaphone
CC=c++
CFLAGS = -Wall -Wextra -Werror --std=c++98


SRCS= megaphone.cpp

all: $(NAME)


$(NAME): $(SRCS)
	$(CC) $(CFLAGS) --std=c++98 $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re