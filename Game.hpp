#include <iostream>

using namespace std;

namespace coup{
    class Game{
        vector <Player> players;
        string curr_turn;
        string game_winner;
        public:
        Game();
        string turn();
        string winner();
    };
};