#ifndef CONTACT_H

# define CONTACT_H

# include <iostream>

class Contact
{
  public:
	std::string fName;
	std::string lName;
	std::string phone;
	std::string nickname;
	std::string secret;

	Contact(void);
	Contact(std::string fName, std::string lName, std::string phone,
		std::string nickname, std::string secret);
	~Contact(void);
};

#endif