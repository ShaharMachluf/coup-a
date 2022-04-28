#pragma once
#include <iostream>
#include "Game.hpp"

using namespace std;

namespace coup{
    class Player{
        protected:
        string name;
        string player_role;
        Game *game;
        int money;
        public:
        Player(Game &g, string n);
        void income();
        void foreign_aid();
        virtual void coup(Player player);
        string role();
        int coins();
        virtual void block(Player player);
        ~Player();
    };
};