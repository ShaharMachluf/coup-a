#include <iostream>
#include "Player.hpp"
#include "Ambassador.hpp"

namespace coup{
    Ambassador::Ambassador(Game g, string n):Player(g,n){}
    void Ambassador::transfer(Player p1, Player p2){}
    void Ambassador::block(Player player){}
};