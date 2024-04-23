NAME=phonebook
CC=g++
CFLAGS = -Wall -Wextra --std=c++98


SRCS= PhoneBook.class.cpp add.cpp Contact.class.cpp main.cpp

all: $(NAME)


$(NAME): $(SRCS)
	$(CC) $(CFLAGS) --std=c++98 $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re