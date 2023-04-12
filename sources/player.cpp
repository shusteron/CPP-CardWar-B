#include "player.hpp"
#include <string>
#include <iostream>
#include "game.hpp"

using namespace std;
using namespace ariel;

Player:: Player(string name){
    this->name = name;
    this->deck={};
    this->won=0;
    this->wins=0;
    this->losses=0;
    this->draws=0;
}

int Player::stacksize(){
    return this->deck.size();
}

int Player::cardesTaken(){
    return this->won;
}

string Player::getName(){
    return this->name;
}

// Pushing a card to player's deck.
void Player::addCard(Card card){
    this->deck.push_back(card);
}

void Player::cardsWon(){
    this->won+=2;
}

void Player::addWin(){
    this->wins++;
}
void Player::addLoss(){
    this->losses++;
}
void Player::addDraw(){
    this->draws++;
}
int Player::getWin(){
    return this->wins;
}
int Player::getDraw(){
    return this->draws;
}
int Player::getLoss(){
    return this->losses;
}

Card Player::getCard(){
    if(this->stacksize()>0){
        Card &card=this->deck.back();
        this->deck.pop_back();
        return card;
    }
    throw invalid_argument("Deck is empty.");
}


