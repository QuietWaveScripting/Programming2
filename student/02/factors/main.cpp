#include <iostream>

void getFactors(int number) {
    // numbers = a * b
    // minimize b - a

    // Initialize aMin and bMin with reasonable default values
    int aMin = 1;
    int bMin = number;

    for (int a = 1; a <= number / 2; a++) {
        if (number % a == 0) {
            int b = number / a;
            int tempDiff = b - a;
            
            if (tempDiff < (bMin - aMin) && tempDiff >= 0) {
                aMin = a;
                bMin = b;
            }
        }
    }

    std::cout << number << " = " << aMin << " * " << bMin << std::endl;
}

int main() {
    std::cout << "Enter a positive number: ";

    int userInput = 0;
    std::cin >> userInput;

    if (userInput <= 0) {
        std::cout << "Only positive numbers accepted" << std::endl;
        return 0;
    }

    getFactors(userInput);

    return 0;
}
