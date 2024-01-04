/* Checkers (for one player)
 *
 * Desc:
 *   This program implements a checkers game for one player. The size of
 * the gameboard is 8 x 8, and it will filled with empty spaces and
 * game pieces (character given by the user).
 *   At first, the gameboard is filled with pieces, but there is an
 * empty area of size 4 x 4 in the middle of the gameboard. The aim is to
 * remove pieces such that only one of them is left. A piece can be moved
 * diagonally over another piece, whereupon the piece that was skipped
 * will be removed.
 *   On each round, the user is asked for two points (four coordinates):
 * the piece to be moved and its target position. The program checks if
 * if the move is possible.
 *   The program terminates when there is only one piece left or if the
 * user gives a quitting command ('q' or 'Q'). In such case the program
 * prints the number of moves made and that of pieces left.
 *
 * Program author
 * Name: Natasha Dmello
 * Student number: 151802762
 * UserID: nrnadm
 * E-Mail: natasha.dmello@tuni.fi
 *
 * */

#include "gameboard.hh"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Splits a string into words using spaces and returns a vector
vector<string> split(string user_input)
{
    vector<string> v = {};
    string temp = user_input;

    while(temp.find("") != string::npos)
    {
        string number = temp.substr(0, temp.find(""));
        temp = temp.substr(temp.find("") + 1, temp.size());
        v.push_back(number);
    }
    v.push_back(temp);
    return v;
}

int main()
{    
    char character = ' ';
    cout << "Enter piece character: ";
    cin >> character;

    GameBoard board;
    board.update_character(character);
    board.print();

    string user_input = "";

    while(true)
    {
        cout << "Enter start point (x, y) and destination point (x, y), or q to quit: ";
        cin.ignore();
        getline(cin, user_input);

        if (user_input == "q")
        {
            break;
        }

        // Split user input into strings
        vector<string> string_numbers = split(user_input);

        // Check if the user input contains more than 4 numbers
        if(string_numbers.size() != 4)
        {
           cout << "Invalid start/destination point." << endl;
           continue;
        }


        // Iterate through the split strings and check if they are valid numbers
        bool error_occurred = false;
        vector<int> numbers;
        for(string& snum: string_numbers)
        {
            // Check if each character in the string is a digit
            for(char digit: snum)
            {
                if(!isdigit(digit))
                {
                    cout << "Invalid start/destination point." << endl;
                    error_occurred = true;
                    break;
                }
            }

           if(error_occurred)
           {
               break;
           }

           // Check if the number is within the valid range
           try
           {
               int num = stoi(snum);
               if(num < 1 || num > 8)
               {
                   cout << "Invalid start/destination point." << endl;
                   error_occurred = true;
                   break;
               }

               if(error_occurred)
               {
                   break;
               }
            }
           catch (std::invalid_argument const &e)
           {
               cout << "Invalid start/destination point." << endl;
               error_occurred = true;
               break;
           }


        if(error_occurred)
        {
            continue;
        }
        }


    }
}
