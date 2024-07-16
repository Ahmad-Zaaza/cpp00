NAME = phonebook

CC = c++

INCLUDES = PhoneBook.hpp Contact.hpp 

CFLAGS = -Wall -Werror -Wextra --std=c++98

SRCS = PhoneBook.class.cpp add.cpp Contact.class.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)


all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re