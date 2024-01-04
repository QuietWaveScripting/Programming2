#include <iostream>

int const KEY_LENGTH = 26;
std::string const KEY_LENGTH_ERROR = "Error! The encryption key must contain 26 characters.",
                  KEY_LOWER_CASE_ERROR = "Error! The encryption key must contain only lower case characters.",
                  KEY_ALL_LETTERS_ERROR = "Error! The encryption key must contain all alphabets a-z.";

bool checkKeyLength(std::string key)
{
    return key.length () == KEY_LENGTH;
}

bool containsAllLetters(std::string key)
{
    for(char letter = 'a'; letter <= 'z'; letter++)
        // check if key contains letter
        if(key.find(letter)== std::string::npos)
        {
            return false;
        }
    return true;
}


std::string encrypt(std::string key, std::string text)
{
    std::string newText = text;
    int index = 0;
    for(char letter : text)
    {
        // get encryption letter index
        int i = letter - 'a';
        newText.at(index) = key.at(i);
        index++;
    }
    return newText;
}


int main()
{
    // get user key input
    std::cout << "Enter the encryption key: ";
    std::string key;
    std::getline(std::cin,key);

    //check key length
    if(!checkKeyLength(key)){
        std::cout << KEY_LENGTH_ERROR << std::endl;
        return EXIT_FAILURE;
    }

    //check a-z
    // loop through letter
    for(char c : key){
        //checking ascii value
        if(c < 'a'|| 'z' < c )
        {
          std::cout << KEY_LOWER_CASE_ERROR << std::endl;
          return EXIT_FAILURE;
        }

    }

    //check all required letters
    if(!containsAllLetters(key))
    {
        std::cout << KEY_ALL_LETTERS_ERROR << std::endl;
        return EXIT_FAILURE;
    }

    //encrypt text
    std::cout << "Enter the text to be encrypted: ";
    std::string text;
    std::getline(std::cin, text);

    // check text
    for(char c : text){
        //checking ascii value
        if(c < 'a'|| 'z' < c )
        {
          std::cout << "Error! The text to be encrypted must contain only lower case characters." << std::endl;
          return EXIT_FAILURE;
        }

    }

    std::cout << "Encrypted text: " << encrypt(key, text) << std::endl;

    return EXIT_SUCCESS;
}
