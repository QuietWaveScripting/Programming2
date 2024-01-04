#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main() {
    std::string filename;
    std::cout << "Input file: ";
    std::cin >> filename;

    std::ifstream input_file(filename);
    if (!input_file) {
        std::cout << "Error! The file " << filename << " cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }

    std::map<std::string, int> scores;
    std::string line;
    while (std::getline(input_file, line)) {
        std::string name = line.substr(0, line.find(":"));
        int points = std::stoi(line.substr(line.find(":") + 1));
        scores[name] += points;
    }

    std::cout << "Final scores:" << std::endl;
    for (const auto &pair : scores) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return EXIT_SUCCESS;
}
