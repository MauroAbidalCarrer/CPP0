#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

bool getUserInput(std::string prompt, std::string& dst)
{
    std::cout << prompt << " :";
    getline(std::cin, dst, '\n');
    return std::cin.eof();
}

bool getContactField(std::string prompt, std::string& dst)
{
    if (getUserInput(prompt, dst))
        return true;
    if (dst.empty())
    {
        std::cout << "contact field cannot be empty!" << std::endl;
        return getContactField(prompt, dst);
    }
    return false;
}

int main()
{
    PhoneBook phoneBook;
    std::string userInput;
    while (!getUserInput("enter command", userInput) && userInput != "EXIT")
    {
        if (userInput == "ADD")
        {
            Contact contact;
            if (getContactField("first name", contact.firstName) ||
                getContactField("last name", contact.lastName) ||
                getContactField("nickname", contact.nickname) ||
                getContactField("phone number", contact.phoneNumber) || 
                getContactField("darkest secret", contact.darkestSecret))
                return 0;
            phoneBook.addContact(contact);
        }
        if (userInput == "SEARCH")
        {
            phoneBook.displaySavedContacts();
            if (phoneBook.nbContacts > 0)
            {
                std::string strIndex;
                if (getUserInput("enter contact index", strIndex))
                    return 0;
                phoneBook.displayContactFields(strIndex);
            }
        }
    }
}
