#include <iostream>
#include <vector>
#include "Game.hpp"

using namespace std;

namespace coup{
    Game::Game():curr_turn(NULL), game_winner(NULL){}
    string Game::turn(){return "hi";}
    string Game::winner(){return "hi";}
};