#pragma once
#include <iostream>
#include <vector>

using namespace std; 

namespace coup{
    class Game{
        vector <string> player_list;
        string curr_turn;
        string game_winner;
        public:
        Game();
        vector <string> players();
        string turn();
        string winner();
    };
};