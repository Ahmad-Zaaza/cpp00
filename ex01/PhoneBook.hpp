#ifndef PHONE_BOOK_H

# define PHONE_BOOK_H

# define MAX_CONTACTS 8
# define MAX_TEXT_LENGTH 10

# include "./Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
  private:
	int _numofContacts;
	int _nextIndex;

  public:
	Contact contacts[MAX_CONTACTS];
	PhoneBook(void);
	~PhoneBook(void);

	int getNumOfContacts(void) const;
	int getNextIndex(void) const;
	void setNextIndex(int index);
	void incrementNumOfContacts(void);

	void add_to_contacts(Contact contact, int index);
	Contact new_contact(std::string fName, std::string lName, std::string phone,
		std::string nickname, std::string secret);
	void list_contacts(void) const;
	void print_contact(int index) const;
};

void	handle_add(PhoneBook *phonebook);
void	handle_search(PhoneBook *phonebook);
std::string truncate(std::string text, std::size_t width = MAX_TEXT_LENGTH);

#endif