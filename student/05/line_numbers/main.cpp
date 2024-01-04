#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputFile, outputFile;

    // Ask the user for input and output file names
    std::cout << "Input file: ";
    std::cin >> inputFile;

    std::cout << "Output file: ";
    std::cin >> outputFile;

    // Open the input file
    std::ifstream input(inputFile);

    // Check if the input file opened successfully
    if (!input.is_open()) {
        std::cerr << "Error! The file " << inputFile << " cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }

    // Open the output file
    std::ofstream output(outputFile);

    std::string line;
    int lineNumber = 1;

    // Read each line from the input file and write to the output file with line numbers
    while (std::getline(input, line)) {
        output << lineNumber << " " << line << std::endl;
        ++lineNumber;
    }

    // Close the files
    input.close();
    output.close();

    return 0;
}
