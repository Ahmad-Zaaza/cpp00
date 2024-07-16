#include "PhoneBook.hpp"
#include <iostream>

static std::string getField(std::string promptTitle)
{
	int	done;

	std::string value;
	done = false;
	while (!done)
	{
		std::cout << "Enter " << promptTitle << ": " << std::endl;
		std::getline(std::cin, value);
		if (value.empty())
			std::cout << "Invalid input: cannot be empty" << std::endl;
		else
			done = true;
	}
	return (value);
}

static bool	is_valid_number(std::string input)
{
	std::string::const_iterator it = input.begin();
	while (it != input.end())
	{
		if (!std::isdigit(*it))
		{
			std::cout << "Invalid input: provide a proper number" << std::endl;
			return (false);
		}
		++it;
	}
	return (true);
}

static std::string getNumberField(std::string promptTitle)
{
	bool	done;

	std::string value;
	done = false;
	while (!done)
	{
		std::cout << "Enter " << promptTitle << ": " << std::endl;
		std::getline(std::cin, value);
		if (value.empty())
			std::cout << "Invalid input: cannot be empty" << std::endl;
		else
		{
			if (is_valid_number(value))
			{
				done = true;
				break ;
			}
		}
	}
	return (value);
}

void	handle_add(PhoneBook *phonebook)
{
	Contact	contact;
	int		numOfContacts;

	std::string fName;
	std::string lName;
	std::string phone;
	std::string nickname;
	std::string secret;
	fName = getField("First name");
	lName = getField("Last name");
	phone = getNumberField("Phone number");
	nickname = getField("nickname");
	secret = getField("their darkest secret");
	contact = phonebook->new_contact(fName, lName, phone, nickname, secret);
	numOfContacts = phonebook->getNumOfContacts();
	if (numOfContacts != MAX_CONTACTS)
		phonebook->incrementNumOfContacts();
	phonebook->add_to_contacts(contact, phonebook->getNextIndex());
	phonebook->setNextIndex((phonebook->getNextIndex() + 1) % MAX_CONTACTS);
}

void	handle_search(PhoneBook *phonebook)
{
	int	index;

	if (phonebook->getNumOfContacts() == 0)
	{
		std::cout << std::setfill('-');
		std::cout << std::setw(19) << "" << std::endl;
		std::cout << std::setfill(' ');
		std::cout << "|";
		std::cout << std::setw(10) << "No Contacts found";
		std::cout << "|" << std::endl;
		std::cout << std::setfill('-');
		std::cout << std::setw(19) << "" << std::endl;
		return ;
	}
	phonebook->list_contacts();
	index = std::atoi(getField("contact index to get information").c_str());
	if (index < 1 || index > phonebook->getNumOfContacts())
		std::cout << "Invalid index, Please enter a valid index" << std::endl;
	else
		phonebook->print_contact(index - 1);
}
