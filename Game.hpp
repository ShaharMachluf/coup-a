#pragma once
#include <iostream>
#include <vector>
#include "Player.hpp"

using namespace std; 

namespace coup{
    class Game{
        vector <string> player_list;
        vector <coup::Player> Player_obj_list;
        unsigned int curr_turn;
        string game_winner;
        string last_out;
        int last_i_out;
        public:
        Game();
        vector <string> players();
        vector <coup::Player> get_players();
        string turn();
        void next_turn();
        string winner();
        void remove_player(string name);
        void assassination(string name);
        void add_player(coup::Player &player);
        void put_back();
    };
};