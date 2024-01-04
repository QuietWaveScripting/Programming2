/*Program author
 * Name: Natasha Dmello
 * Student number: 151802762
 * UserID: nrnadm
 * E-Mail: natasha.dmello@tuni.fi
 *
 * */


#include "gameboard.hh"
#include <iostream>
#include <vector>


GameBoard::GameBoard()
{

}

void GameBoard::print() const
{
    // Printing upper border
    print_line(LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '=');

    // Printing title row
    std::cout << "|   | ";
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        std::cout << i + 1 << " ";
    }
    std::cout << "|" << std::endl;

    // Printing line after the title row
    print_line(LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '-');


    // Printing the actual content of the gameboard
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        std::cout << "| " << i + 1 << " |";
        std::cout << " ";
        for(unsigned int j = 0; j < SIZE; ++j)
        {

            // Print here empty or the element (i, j) in the gameboard

            if(i == 0 or i == 1 or i == SIZE - 1 or i == SIZE - 2)
            {
                std::cout << game_character_ << " ";
            }
            else
            {
                if(j == 0 or j== 1 or j == SIZE - 1 or j == SIZE - 2)
                {
                   std::cout << game_character_ << " ";
                }
                else
                {
                    std::cout << "  ";
                }
            }
        }
        std::cout << "|" << std::endl;
    }

    // Printing lower border
    print_line(LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '=');
}

void GameBoard::update_character(char character)
{
    game_character_ = character;
}

void GameBoard::print_line(unsigned int length, char fill_character) const
{
    for(unsigned int i = 0; i < length; ++i)
    {
        std::cout << fill_character;
    }
    std::cout << std::endl;
}



