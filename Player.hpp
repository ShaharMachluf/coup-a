#include <iostream>
#include "Game.hpp"

namespace coup{
    class Player{
        string name;
        string role;
        Game game;
        int money;
        public:
        Player(Game g, string n);
        void income();
        void foreign_aid();
        virtual void coup(Player player);
        string role();
        string coins();
        virtual void block(Player player);
        ~Player();
    };
};