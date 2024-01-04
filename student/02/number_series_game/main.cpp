#include <iostream>

int main()
{
    std::cout << "How many numbers would you like to have? ";

    int numNumbers;
    std::cin >> numNumbers;

    // Print the numbers, replacing numbers divisible by 3 with "zip",
    // numbers divisible by 7 with "boing", and both with "zip boing"
    for (int i = 1; i <= numNumbers; ++i) {
        if (i % 3 == 0 && i % 7 == 0) {
            std::cout << "zip boing\n";
        } else if (i % 3 == 0) {
            std::cout << "zip\n";
        } else if (i % 7 == 0) {
            std::cout << "boing\n";
        } else {
            std::cout << i << "\n";
        }
    }

    return 0;
}
