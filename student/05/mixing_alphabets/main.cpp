#include <iostream>
#include <string>
#include <algorithm>
#include <random>

void mix_word_letters(std::string &word, std:: minstd_rand &gen){
    //check if string is long enough (>2)
    if (word.length() <= 2) {return;}
    //shuffle letters between first and last letter
    std::string::iterator iter_start = word.begin(),
                          iter_end = word.end();
    std::shuffle(++iter_start, --iter_end, gen);

}


int main()
{
    // This is a random number generator that should be given as parameter to the
    // function of the algorithm library to shuffle letters
    std::minstd_rand generator;

    std::cout << "Enter some text. Quit by entering the word \"END\"." << std::endl;
    std::string word;

    while (std::cin >> word)
    {
        if (word == "END")
        {
            return EXIT_SUCCESS;
        }

        mix_word_letters(word, generator);

	
        std::cout << word << std::endl;
    }
}
