#include <iostream>


int main()
{
    // ask for input
    std::cout << "Enter a number: ";
    int number = 0;
    std::cin >> number;

    int cube = number*number*number;
    //validate cube value
    if (cube/number/number == number)
    {
       std::cout << "The cube of " << number << " is " << cube << "." << std::endl;
    }
    else {
        std::cout << "Error! The cube of " << number << " is not " << cube << "." << std::endl;
    }
    return 0;
}
