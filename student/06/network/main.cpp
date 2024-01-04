#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

const std::string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";


std::vector<std::string> split(const std::string& s,
                               const char delimiter,
                               bool ignore_empty = false)
{
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

using ntwk = std::map <std::string, std::vector<std::string>>;

void store(std::string const &recruiter, std::string const &person, ntwk &net){
    //check if it is already in network
    if(net.find(recruiter) == net.end()){
        net.insert({recruiter, {}});

    }
    net.at(recruiter).push_back(person);

    //check if person in network is a recruiter
    if (net.find(person) == net.end()){
        net.insert({person, {}});

    }

}

void print(std::string const &person, ntwk const &net, std::string indent){

    // default when the subnet is empty
    std::cout << indent << person << std::endl;

    // else print the subnetwork
    for(std::string const &p : net.at(person)){
        print(p, net, indent + ".." );
    }
}

int count (std::string const &person , ntwk const &net){

    // default - no subnet
    if (net.at(person).empty()){
        return 0;
    }

    int n = 0;
    // loop through subnet
    for (std::string const&p : net.at(person)){
        n += count(p, net);
        n++;
    }
      return n;
}

int depth (std::string const &person , ntwk const &net){

    int deepest = 0;
    //loop subnet
    for (std::string const &p : net.at(person))
    {
        int d = depth(p,net);
        if(d > deepest){
                deepest = d;
        }

    }

    return deepest + 1;
}



int main()
{
    // map, <recruiter, set of recruits>
    ntwk net;




    while(true)
    {
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        // Allowing empty inputs
        if(parts.size() == 0)
        {
            continue;
        }

        std::string command = parts.at(0);

        if(command == "S" or command == "s")
        {
            if(parts.size() != 3)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            // DONE: Implement the command here!
            store(id1, id2, net);

        }
        else if(command == "P" or command == "p")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // DONE: Implement the command here!
            print(id, net, "");


        }
        else if(command == "C" or command == "c")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // DONE: Implement the command here!
            std::cout << count(id, net) << std::endl;

        }
        else if(command == "D" or command == "d")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // DONE: Implement the command here!
            std::cout << depth(id, net) << std::endl;

        }
        else if(command == "Q" or command == "q")
        {
           return EXIT_SUCCESS;
        }
        else
        {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
