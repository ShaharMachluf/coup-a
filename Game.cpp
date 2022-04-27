#include <iostream>
#include <vector>
#include "Player.hpp"

using namespace std;
using std::vector;

namespace coup{
    Game::Game():curr_turn(NULL), game_winner(NULL){}
    string Game::turn(){return "hi";}
    string Game::winner(){return "hi";}
};