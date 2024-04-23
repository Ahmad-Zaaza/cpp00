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
		std::cin >> value;
		if (!value.length())
			std::cout << "Invalid input" << std::endl;
		else
			done = true;
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
	phone = getField("Phone number");
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

	phonebook->list_contacts();
	index = std::atoi(getField("contact index to get information").c_str());
	if (index < 1 || index > phonebook->getNumOfContacts())
		std::cout << "Invalid index, Please enter a valid index" << std::endl;
	else
		phonebook->print_contact(index - 1);
}
