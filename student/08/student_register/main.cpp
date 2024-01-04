#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

const std::string HELP_TEXT = "N                  = List ordered by student numbers\n"
                              "U                  = List ordered alphabetically by user ids\n"
                              "C <student_number> = Change the given student's phone number\n"
                              "Q                  = Quit\n";

struct Student {
    std::string student_number;
    std::string user_id;
    std::string name;
    std::string phone_number;
    std::string email;
    std::string skype;
};


// alias datastructure
using DATA = std::map< std::string, Student* >;


std::vector<std::string> split(const std::string& s,
                               const char delimiter,
                               const bool ignore_empty = false) {
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos) {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty())) {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty())) {
        result.push_back(tmp);
    }
    return result;
}


bool read_data(const std::string& file_name,
               std::map< std::string, Student* >& alphabetical_order,
               std::map< std::string, Student* >& numerical_order) {
    std::ifstream file_object(file_name);
    if( !file_object ) {
        return false;
    }

    std::string line = "";

    while( getline( file_object, line ) ) {
        std::vector<std::string> parts = split(line, ';');
        if(parts.size() != 6) {
            return false;
        }

        Student* new_student = new Student({parts[0],
                                            parts[1],
                                            parts[2],
                                            parts[3],
                                            parts[4],
                                            parts[5]});
        numerical_order[parts[0]] = new_student;
        alphabetical_order[parts[1]] = new_student;
    }
    file_object.close();
    return true;
}


void print_data(const Student& s) {
    std::cout << s.student_number << " " << s.user_id << std::endl
              << s.name << std::endl
              << s.phone_number << std::endl
              << s.email << std::endl
              << s.skype << std::endl << std::endl;
}

bool is_valid_phone_number(const std::string number) {
    for(unsigned int i = 0; i < number.length(); ++i) {
        if(!(('0' <= number[i] and number[i] <= '9')
             or number[i] == ' '
             or number[i] == '-')) {
            std::cout << "Erroneous phone number: "
                      << number
                      << std::endl << std::endl;
            return false;
        }
    }
    return true;
}

//create function to find student pointer
Student* get_student(DATA const&data, std::string id){

    //check if student in database
    if (data.find(id) == data.end()){
        std::cout << "There is no student with the given number!" << std::endl;
        return nullptr;
    }
    return data.at(id);
}

std::string get_phone(){
    std::cout << "Enter a new phone number: ";
    std:: string phone;
    std:: getline(std::cin, phone);

    //check number
    // output formatting
    std::cout << std::endl;
    return (is_valid_phone_number(phone)) ? phone : "";
}

void save_data_to_file(std::string filename, DATA const &numbers_data)
{
    //open file
    std::ofstream file(filename);
    if(file){
        //go through students
        for(std::pair<std::string, Student*> student: numbers_data){
            //compose line
            Student *s = student.second;
            std::string line = s->student_number + ';'
                              +s->user_id +';'
                              +s->name +';'
                              +s->phone_number +';'
                              +s->email +';'
                              +s->skype;
            // write the line to file
            file << line << std::endl;

        }
    }
    file.close();
}

int main() {
    std::string file_name = "";
    std::cout << "Student file: ";
    std::getline(std::cin, file_name);

    std::map< std::string, Student* > user_ids;
    std::map< std::string, Student* > student_numbers;
    if(not read_data(file_name, user_ids, student_numbers)) {
        std::cout << "Error in reading file!" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << HELP_TEXT << std::endl;

    while(true) {
        std::string line;
        std::cout << "register> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        if(parts.empty()) {
            continue;
        }
        std::string command = parts.at(0);

        // Printing in alphabetical order by user ids
        if(command == "U" or command == "u") {
            if(parts.size() != 1) {
                std::cout << "Erroneous parameters!" << std::endl  << HELP_TEXT;
                continue;
            } else {
                for(auto pair: user_ids) {
                    print_data(*(pair.second));
                }
            }

            // Printing in numerical order by student numbers
        } else if(command == "N" or command == "n") {
            if(parts.size() != 1){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            } else {
                for(auto pair: student_numbers) {
                    print_data(*(pair.second));
                }
            }

            // Changing student data
        } else if(command == "C" or command == "c") {
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            // DONE: Add functionality here
            // get student
            std::string student_id = parts.at(1);
            Student* ptr = get_student(student_numbers, student_id);
            //student not found
            if(ptr ==nullptr){continue;}

            // get phone number
            std::string phone = get_phone();
            // phone invalid
            if(phone.empty()){continue;}

            // modify data
            ptr->phone_number = phone;

        } else if(command == "Q" or command == "q") {
            // SAVE DATA TO FILE
            save_data_to_file(file_name, user_ids);

            // Deleting the data structure: deallocating memory
            // and nullifying pointers
            for(auto pair: student_numbers) {
                pair.second = nullptr;
            }

            for(auto pair: user_ids) {
                delete pair.second;
                pair.second = nullptr;
            }

            return EXIT_SUCCESS;
        } else {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}


