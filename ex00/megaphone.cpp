#include <iostream>

int main(int ac, char *av[])
{
    for (int i = 1; i < ac; i++)
    {
        for (int k = 0; av[i][k]; k++)
            av[i][k] = toupper(av[i][k]);
        std::cout << av[i] << std::endl;
    }
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}