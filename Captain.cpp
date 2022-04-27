#include <iostream>
#include "Player.hpp"
#include "Captain.hpp"

namespace coup{
    class Captain:public Player{
        Captain::Captain(Game g, string n):Player(g,n){}
        void Captain::steal(Player player){}
    };
};