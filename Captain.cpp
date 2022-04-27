#include <iostream>
#include "Player.hpp"
#include "Captain.hpp"

namespace coup{
    class Captain:public Player{
        void Captain::steal(Player player){}
    };
};