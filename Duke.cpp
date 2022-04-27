#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"

namespace coup{
    Duke::Duke(Game g, string n):Player(g,n){}
    void Duke::tax(){}
    void Duke::block(Player player){}
};