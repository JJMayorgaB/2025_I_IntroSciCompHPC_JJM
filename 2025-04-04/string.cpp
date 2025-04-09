#include <iostream>
#include <string>

int main(void)
{
    std::string name;
    std::cout <<"Please write your name" << std::endl;

    std::getline(std::cin, name);

    std::cout << "Hola " + name + "\n";

    return 0;
}