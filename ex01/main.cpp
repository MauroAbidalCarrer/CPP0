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

int main()
{
    PhoneBook phoneBook;
    std::string userInput;
    while (!getUserInput("enter command", userInput) && userInput != "EXIT")
    {
        if (userInput == "ADD")
            phoneBook.addContact();
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
