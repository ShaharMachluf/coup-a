#include <iostream>
#include "Player.hpp"
#include "Captain.hpp"

namespace coup{
    Captain::Captain(Game g, string n):Player(g,n){
        this->player_role = "Captain";
    }
    void Captain::steal(Player player){
        check_turn();
        if(player.coins()<2){
            throw("he doesn't have enough coins");
        }
        this->money+=2;
        player.remove_coins(2);
        this->set_last_play("steal", player.get_name());
        game->next_turn();
    }
    void Captain::block(Player player){
        check_turn();
        vector<string>vec = player.get_last_play();
        if(vec.at(0) != "steal"){
            throw("Last action wasn't 'steal'");
        }
        vector<Player*> players = game->get_players();
        for(unsigned int i=0; i<players.size(); i++){
            if((*players.at(i)).get_name() == vec.at(1)){
                (*players.at(i)).add_coins(2);
            }
        }
        player.remove_coins(2);
        this->set_last_play("block", player.get_name());
        game->next_turn();
    }
};