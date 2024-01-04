#ifndef PLAYER_HH
#define PLAYER_HH

#include <string>


const int MAX_POINTS = 50,
          POINTS_RESET = 25;


class Player
{
public:
    Player(std::string const& name);
    void add_points(int points);

    std::string get_name() const;
    int get_points() const;
    bool has_won();






private:
    std::string name_;
    int points_;


};

#endif // PLAYER_HH
