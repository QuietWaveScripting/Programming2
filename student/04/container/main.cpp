#include <cstdlib>
#include <iostream>
#include <vector>


// Prints the elements in the parameter vector ints.
void print_integers(const std::vector< int >& ints){
    for(auto elem : ints) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Reads as many integers as the parameter count indicates
// and stores them into the parameter vector ints.
void read_integers(std::vector<int>& ints, int count) {
    int new_integer = 0;
    for (int i = 0; i < count; ++i) {
        std::cin >> new_integer;
        ints.push_back(new_integer);
    }
}

bool same_values(const std::vector<int>& ints) {
    if (ints.empty()) return true;

    int first = ints[0];
    for (size_t i = 1; i < ints.size(); ++i) {
        if (ints[i] != first) {
            return false;
        }
    }
    return true;
}

bool is_ordered_non_strict_ascending(const std::vector<int>& ints) {
    if (ints.empty()) return true;

    int prev = ints[0];
    for (size_t i = 1; i < ints.size(); ++i) {
        if (ints[i] < prev) {
            return false;
        }
        prev = ints[i];
    }
    return true;
}

bool is_arithmetic_series(const std::vector<int>& ints) {
    if (ints.size() < 2) return true;

    int diff = ints[1] - ints[0];
    for (size_t i = 1; i < ints.size(); ++i) {
        if (ints[i] - ints[i - 1] != diff) {
            return false;
        }
    }
    return true;
}

bool is_geometric_series(const std::vector<int>& ints) {
    if (ints.size() < 2) return true;

    if (ints[0] == 0) {
        for (size_t i = 1; i < ints.size(); ++i) {
            if (ints[i] != 0) {
                return false;
            }
        }
        // A sequence of zeros is not considered a geometric series
        return false;
    } else {
        double ratio = static_cast<double>(ints[1]) / ints[0];
        for (size_t i = 2; i < ints.size(); ++i) {
            if (static_cast<double>(ints[i]) / ints[i - 1] != ratio) {
                return false;
            }
        }
        return true;
    }
}



void triple_integers(std::vector<int>& ints) {
    for (size_t i = 0; i < ints.size(); ++i) {
        ints[i] *= 3;
    }
}


int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    if(how_many <= 0) {
        return EXIT_FAILURE;
    }

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers)) {
        std::cout << "All the integers are the same" << std::endl;
    } else {
        std::cout << "All the integers are not the same" << std::endl;
    }

    if(is_ordered_non_strict_ascending(integers)) {
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    } else {
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;
    }

    if(is_arithmetic_series(integers)) {
        std::cout << "The integers form an arithmetic series" << std::endl;
    } else {
        std::cout << "The integers do not form an arithmetic series" << std::endl;
    }

    if(is_geometric_series(integers)) {
        std::cout << "The integers form a geometric series" << std::endl;
    } else {
        std::cout << "The integers do not form a geometric series" << std::endl;
    }

    triple_integers(integers);
    std::cout << "Tripled values: ";
    print_integers(integers);

    return EXIT_SUCCESS;
}
