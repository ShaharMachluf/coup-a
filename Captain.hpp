#include <iostream>
#include "Player.hpp"

namespace coup{
    class Captain:public Player{
        void steal(Player player);
    };
};