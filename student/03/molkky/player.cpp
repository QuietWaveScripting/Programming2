#include "player.hh"

Player::Player(const std::string &name):
    name_(name),
    points_(0)
{

}

void Player::add_points(int points)
{
    // increase points
    points_ += points;


   // points_ = (points_ > MAX_POINTS) ? POINTS_RESET : points_;

    // check if points go over maximum
    if (points_> MAX_POINTS)
    {
        // set points back
        points_ = POINTS_RESET;
    }

}

std::string Player::get_name() const
{
    return name_;

}

int Player::get_points() const
{
    return points_;

}

bool Player::has_won()
{
    return points_== MAX_POINTS;

}
