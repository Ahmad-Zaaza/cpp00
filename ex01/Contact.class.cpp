#include "./Contact.hpp"
#include <iostream>

// Default Constructor
Contact::Contact(void)
{
}

// Constructor
Contact::Contact(std::string fName, std::string lName, std::string phone,
	std::string nickname, std::string secret) : fName(fName), lName(lName),
	phone(phone), nickname(nickname), secret(secret)
{
}
// Destructor
Contact::~Contact(void){};
