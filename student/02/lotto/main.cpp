#include <iostream>

unsigned long long int calculateCombination(int n, int k) {
    unsigned long long int result = 1;
    for (int i = 1; i <= k; ++i) {
        result *= n - i + 1;
        result /= i;
    }
    return result;
}

double calculateProbability(int totalBalls, int drawnBalls) {
    if (totalBalls <= 0) {
        std::cout << "The number of balls must be a positive number." << std::endl;
        return -1.0;  // Return -1.0 to indicate an error
    }

    if (drawnBalls <= 0 || drawnBalls > totalBalls) {
        std::cout << "The maximum number of drawn balls is the total amount of balls." << std::endl;
        return -1.0;  // Return -1.0 to indicate an error
    }

    unsigned long long int numerator = 1;
    for (int i = totalBalls; i > totalBalls - drawnBalls; --i) {
        numerator *= i;
    }

    unsigned long long int denominator = 1;
    for (int i = 1; i <= drawnBalls; ++i) {
        denominator *= i;
    }

    return 1.0 / (numerator / denominator);
}

int main() {
    int totalBalls, drawnBalls;

    std::cout << "Enter the total number of lottery balls: ";
    std::cin >> totalBalls;

    std::cout << "Enter the number of drawn balls: ";
    std::cin >> drawnBalls;

    double probability = calculateProbability(totalBalls, drawnBalls);

    if (probability != -1.0) {
        std::cout << "The probability of guessing all " << drawnBalls << " balls correctly is 1/" << 1.0 / probability << std::endl;
    }

    return 0;
}
