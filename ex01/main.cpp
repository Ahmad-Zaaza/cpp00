#include "./PhoneBook.hpp"
#include <string>

int	main(void)
{
	std::string cmd;
	PhoneBook phonebook;

	while (true)
	{
		std::cout << "Enter a command:" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd.empty())
			continue ;
		if (cmd == "ADD")
			handle_add(&phonebook);
		else if (cmd == "SEARCH")
			handle_search(&phonebook);
		else if (cmd == "EXIT")
			break ;
		else
		{
			std::cout << "Unknown command provided \n\
Known commands are : ADD, \
SEARCH and EXIT" << std::endl;
		}
		cmd = "";
	}
	return (0);
}