#include <iostream>
#include <vector>
#include "Game.hpp"

using namespace std;

namespace coup{
    Game::Game(){}
    vector <string> Game::players(){
        vector<string> vec = {"hi"};
        return vec;
    }
    string Game::turn(){return "hi";}
    string Game::winner(){return "hi";}
};