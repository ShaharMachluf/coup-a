#include <iostream>
#include "Player.hpp"
#include "Captain.hpp"

namespace coup{
    Captain::Captain(Game g, string n):Player(g,n){}
    void Captain::steal(Player player){}
};