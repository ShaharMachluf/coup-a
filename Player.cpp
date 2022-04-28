#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

namespace coup{
    Player::Player(Game &g, string n):game(&g), name(n){}
    void Player::income(){}
    void Player::foreign_aid(){}
    void Player::coup(Player player){}
    string Player::role(){return "hi";}
    int Player::coins(){return 1;}
    void Player::block(Player player){}
    Player::~Player(){}
};