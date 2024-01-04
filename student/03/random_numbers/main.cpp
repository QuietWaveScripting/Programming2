#include <iostream>
#include <random>
#include <string>

using namespace std;

void produce_random_numbers(unsigned int lower, unsigned int upper, unsigned int seed)
{
    // Initialize the random number generator with the provided seed value
    default_random_engine gen(seed);

    uniform_int_distribution<int> distr(lower, upper);

    char userInput;
    do
    {
        int random_number = distr(gen);
        cout << "\nYour drawn random number is " << random_number << endl;
        cout << "Press q to quit or any other key to continue: ";
        cin >> userInput;

    } while (userInput != 'q' && userInput != 'Q');
}

int main()
{
    unsigned int lower_bound, upper_bound, seed_value;
    cout << "Enter a lower bound: ";
    cin >> lower_bound;
    cout << "Enter an upper bound: ";
    cin >> upper_bound;

    if (lower_bound >= upper_bound)
    {
        cout << "The upper bound must be strictly greater than the lower bound" << endl;
        return EXIT_FAILURE;
    }

    cout << "Enter a seed value: ";
    cin >> seed_value;

    produce_random_numbers(lower_bound, upper_bound, seed_value);

    return EXIT_SUCCESS;
}
