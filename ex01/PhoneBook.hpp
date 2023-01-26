
#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include <string>
# include <iostream>
# include <cstdlib>
# include <iomanip>
# include "Contact.hpp"
# define MAX_NB_CONTACTS 8

class PhoneBook
{
    private:
    int nextContactIndex;
    Contact contacts[MAX_NB_CONTACTS];
    void displayContactFieldInColumn(std::string field);

    public:
    int nbContacts;
    PhoneBook();
    void addContact(Contact newContact);
    void displaySavedContacts();
    void displayContactFields(std::string contactStrIndex);
};

#endif