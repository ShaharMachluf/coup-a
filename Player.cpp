#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

namespace coup{
    Player::Player(Game &g, string n):game(&g), name(n), money(0){
        game->add_player(*this);
        this->action.push_back(NULL);
        this->action.push_back(NULL);
    }
    void Player::check_turn(){
        if(game->turn() != this->name){
            throw("It's not your turn");
        }
    }
    void Player::income(){
        check_turn();
        this->money++;
        this->set_last_play("income", this->name);
        game->next_turn();
    }
    void Player::foreign_aid(){
        check_turn();
        this->money+=2;
        this->set_last_play("foreign_aid", this->name);
        game->next_turn();
    }
    void Player::coup(Player player){
        check_turn();
        if(this->money<7){
            throw("You don't have enough coins for this action");
        }
        game->remove_player(player.name);
        this->set_last_play("coup", player.name);
        this->money-=7;
        game->next_turn();
    }
    string Player::role(){return this->player_role;}
    int Player::coins(){return this->money;}
    void Player::block(Player player){}
    void Player::add_coins(int num){this->money+=num;}
    void Player::remove_coins(int num){this->money-=num;}
    string Player::get_name(){
        return this->name;
    }
    vector<string> Player::get_last_play(){
        return this->action;
    }
    void Player::set_last_play(string act, string done_to){
        this->action.at(0) = act;
        this->action.at(1) = done_to;
    }
};