
#ifndef CONTACT_H
# define CONTACT_H
# include<string>

class Contact
{
    private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    public:
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
    bool setFields();
    void test();
};
#endif