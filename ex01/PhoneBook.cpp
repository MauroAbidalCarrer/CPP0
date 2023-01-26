#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    nextContactIndex = 0;
    nbContacts = 0;
}

void PhoneBook::addContact(Contact newContact)
{
    contacts[nextContactIndex] = newContact;
    nextContactIndex = (nextContactIndex + 1) % MAX_NB_CONTACTS;
    nbContacts = std::min(nbContacts + 1, MAX_NB_CONTACTS);
}

void PhoneBook::displaySavedContacts()
{
    std::cout << "   index  |first name|last  name| nickname |  secret  " << std::endl;
    for (int i = 0; i < nbContacts; i++)
    {
        std::cout << std::setw(10) << i << "|";
        Contact contact = contacts[i];
        displayContactFieldInColumn(contact.firstName);
        std::cout << '|';
        displayContactFieldInColumn(contact.lastName);
        std::cout << '|';
        displayContactFieldInColumn(contact.nickname);
        std::cout << '|';
        displayContactFieldInColumn(contact.darkestSecret);
        std::cout << std::endl;
    }
}

void PhoneBook::displayContactFieldInColumn(std::string field)
{
    std::string truncated = field.substr(0, 10);
    if (field.size() > 10)
        truncated[9] = '.';
    std::cout << std::setw(10) << truncated;
}

void PhoneBook::displayContactFields(int contactIndex)
{
    if (contactIndex >= nbContacts || contactIndex < 0)
    {
        std::cerr << "ERROR: wrong contactIndex!" << std::endl;
        return;
    }
    Contact contact = contacts[contactIndex];
    std::cout << "first name: \"" << contact.firstName << "\"" << std::endl;
    std::cout << "last name: \"" << contact.lastName << "\"" << std::endl;
    std::cout << "nickname: \"" << contact.nickname << "\"" << std::endl;
    std::cout << "darkest secret: \"" << contact.darkestSecret << "\"" << std::endl;
}