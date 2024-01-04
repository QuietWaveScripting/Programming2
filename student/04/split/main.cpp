#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string const &line, char sep, bool ignore_empty = false)
{
    std::vector <std::string> parts;
    //loop through the line
    // add letters to words. if  sep -> add word to vec -> reset
    std::string current_word = "";
    for (char c : line){
        if(c != sep)
        {
            current_word += c;
            continue;
        }

        //check emptiness
        if(!(current_word.empty() && ignore_empty))
        {
            parts.push_back(current_word);
        }
        current_word.clear();
    }
    if(!(current_word.empty() && ignore_empty))
    {
        parts.push_back(current_word);
    }
    return parts;
}




int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
