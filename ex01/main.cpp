#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    PhoneBook phoneBook;
    std::string userInput;
    do
    {
        std::cout << "action: ";
        std::cin >> userInput;
        if (userInput == "ADD")
        {
            Contact contact;
            std::cout << "first name: ";
            std::cin >> contact.firstName;
            std::cout << "last name: ";
            std::cin >> contact.lastName;
            std::cout << "nickname: ";
            std::cin >> contact.nickname;
            std::cout << "darkest secret: ";
            std::cin >> contact.darkestSecret;
            phoneBook.addContact(contact);
        }
        if (userInput == "SEARCH")
        {
            phoneBook.displaySavedContacts();
            if (phoneBook.nbContacts > 0)
            {
                std::cout << "contact index: ";
                int index;
                std::cin >> index;
                phoneBook.displayContactFields(index);
            }
        }
    } while (userInput != "EXIT");
}