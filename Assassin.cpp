#include <iostream>
#include "Player.hpp"
#include "Assassin.hpp"

namespace coup{
    Assassin::Assassin(Game g, string n):Player(g,n){}
    void Assassin::coup(Player player){}
}