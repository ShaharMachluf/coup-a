#include <iostream>
#include "Player.hpp"

namespace coup{
    class Duke:public Player{
        public:
        void tax();
        void block(Player player);
    };
};