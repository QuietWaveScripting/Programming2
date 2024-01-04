/*Program author
 * Name: Natasha Dmello
 * Student number: 151802762
 * UserID: nrnadm
 * E-Mail: natasha.dmello@tuni.fi
 *
 * */

#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include<vector>

// Size of the gameboard
const unsigned int SIZE = 8;

// Width of the left-most column, needed in printing the gameboard
const unsigned int LEFT_COLUMN_WIDTH = 5;

// GameBoard class
class GameBoard
{
public:
    // Constructor: you can add parameters if needed
    GameBoard();

    // Prints the gameboard (after you have finished the method).
    void print() const;

    // Updates the game_character_ variable with the character the user inputs
    void update_character(char character);


private:
    // Prints a line with the given length and fill character.
    void print_line(unsigned int length, char fill_character) const;
    char game_character_ = ' ';

};

#endif // GAMEBOARD_HH
