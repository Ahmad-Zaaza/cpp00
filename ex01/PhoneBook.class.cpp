#include "./PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook(void) : _numofContacts(0), _nextIndex(0){};
// Destructor
PhoneBook::~PhoneBook(void){};

int PhoneBook::getNumOfContacts(void) const
{
	return (this->_numofContacts);
};
int PhoneBook::getNextIndex(void) const
{
	return (this->_nextIndex);
};
void PhoneBook::incrementNumOfContacts(void)
{
	this->_numofContacts += 1;
}

void PhoneBook::setNextIndex(int index)
{
	this->_nextIndex = index;
}

void PhoneBook::add_to_contacts(Contact contact, int index)
{
	this->contacts[index] = contact;
};

Contact PhoneBook::new_contact(std::string fName, std::string lName,
	std::string phone, std::string nickname, std::string secret)
{
	Contact contact(fName, lName, phone, nickname, secret);
	return (contact);
};
void PhoneBook::list_contacts(void) const
{
	std::ios init(NULL);
	init.copyfmt(std::cout);
	int i;
	i = 0;
	std::cout << std::setfill('-');
	std::cout << std::setw(45) << "" << std::endl;
	std::cout.copyfmt(init);
	std::cout << "|";
	std::cout << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::setw(10) << "first name";
	std::cout << "|";
	std::cout << std::setw(10) << "last name";
	std::cout << "|";
	std::cout << std::setw(10) << "nickname";
	std::cout << "|" << std::endl;
	std::cout << std::setfill('-');
	std::cout << std::setw(45) << "" << std::endl;
	std::cout.copyfmt(init);
	while (i < this->getNumOfContacts())
	{
		std::cout << "|";
		std::cout << std::setw(10) << i + 1;
		std::cout << "|";
		std::cout << std::setw(10) << truncate(contacts[i].fName).c_str();
		std::cout << "|";
		std::cout << std::setw(10) << truncate(contacts[i].lName).c_str();
		std::cout << "|";
		std::cout << std::setw(10) << truncate(contacts[i].phone).c_str();
		std::cout << "|" << std::endl;
		// printf("%11d|%11s|%11s|%11s\n", i + 1,
		// 	truncate(contacts[i].fName).c_str(),
		// 	truncate(contacts[i].lName).c_str(),
		// 	truncate(contacts[i].phone).c_str());
		i++;
	}
	std::cout << std::setfill('-');
	std::cout << std::setw(45) << "" << std::endl;
	std::cout.copyfmt(init);
};

void PhoneBook::print_contact(int index) const
{
	std::cout << "First Name: " << contacts[index].fName << std::endl;
	std::cout << "Last Name: " << contacts[index].lName << std::endl;
	std::cout << "Phone number: " << contacts[index].phone << std::endl;
	std::cout << "Nickname: " << contacts[index].nickname << std::endl;
};

std::string truncate(std::string text, std::size_t width)
{
	if (text.length() > width)
		return (text.substr(0, width - 1) + ".");
	return (text);
}