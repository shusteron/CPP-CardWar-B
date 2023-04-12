#include "game.hpp"
#include <stdio.h>
#include "card.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>

#define PRINCE 11
#define QUEEN 12
#define KING 13
#define ACE 1


int draws=0;


namespace ariel{}
using namespace std;

Game::Game(Player &p1, Player &p2):
p1_(p1),p2_(p2)
{
    this->last_turn="";
    this->last_turn="";
    this->cards={};

    createDeck();
    splitDecks();
}

void Game::createDeck(){
    // Each for loop for card shape.
    for(int i=1;i<=13;i++){
        Card card("hearts",i);
        this->cards.push_back(card);
    }
    for(int i=1;i<=13;i++){
        Card card("clubs",i);
        this->cards.push_back(card);
    }
    for(int i=1;i<=13;i++){
        Card card("diamonds",i);
        this->cards.push_back(card);
    }
    for(int i=1;i<=13;i++){
        Card card("spades",i);
        this->cards.push_back(card);
    }
    // Shuffles the deck.
    shuffle();
}

void Game::shuffle(){
    auto rd = random_device{};
    auto rng = default_random_engine{rd()};
    ::shuffle(begin(this->cards),end(this->cards),rng);
}
void Game::splitDecks(){
    // Dealing the deck to the players.
    for(int i=1;i<53;i++){
        if(i<=26){
            this->p1_.addCard(this->cards.back());
            this->cards.pop_back();
        }
        else{
            this->p2_.addCard(this->cards.back());
            this->cards.pop_back();
        }
    }        
}
string Game::getTurn(string name, Card card){
    if(card.getValue()==PRINCE){
        return name + " played prince of " + card.getShape()+".";
    }
    if(card.getValue()==QUEEN){
        return name + " played queen of " + card.getShape()+".";
    }
    if(card.getValue()==KING){
        return name + " played king of " + card.getShape()+".";
    }
    if(card.getValue()==ACE){
        return name + " played ace of " + card.getShape()+".";
    }
    
    return name + " played " + to_string(card.getValue()) + " of " + card.getShape()+".";

}

int Game::battle(Player p1, Player p2, Card card1, Card card2){
    // A method that recieves two players and cards and returns 0/1/2.
    // 0 - draw.
    // 1- p1 won.
    // 2- p2 won.
    if(card1.getValue() == 1){
        if(card2.getValue()==2){
            return 2;
        }
        else{
            return 1;
        }
    }
    else if(card2.getValue() == 1){
        if(card1.getValue()==2){
            return 1;
        }
        else{
            return 2;
        }
    }
    else if(card1.getValue()< card2.getValue()){
        return 2;
    }
    else if(card1.getValue() > card2.getValue()){
        return 1;
    }
    else if(card1.getValue()==card2.getValue()){
        return 0;
    }
    return -1;
    
}

void Game::playTurn(){
    // Checks if its same player.
    if(&this->p1_ == &this->p2_){
        throw invalid_argument("received same player");
    }
    // Checks if there are cards to draw.
    if(this->p1_.stacksize()==0){
        throw invalid_argument("No cards left to play.");
    }
    bool winner = false;
    Card card1 = this->p1_.getCard();
    Card card2 = this->p2_.getCard();
    int match = battle(this->p1_,this->p2_,card1,card2);
    while(match==0){
        this->p1_.addDraw();
        this->p2_.addDraw();
        this->last_turn="Draw."+ this->getTurn(this->p1_.getName(),card1)+
                                    this->getTurn(this->p2_.getName(),card2)+"\n";
        this->summary+=this->last_turn;   
        if(this->p1_.stacksize()>=2){
            draws+=4;
            this->p1_.getCard();
            this->p2_.getCard();
            card1 = this->p1_.getCard();
            card2 = this->p2_.getCard();
        }
        else{   //There is not enough cards to play with in a draw case, so each player gets back his own cards.
            while(this->p1_.stacksize()>0){
                this->p1_.getCard();
                this->p2_.getCard();
                this->p1_.cardsWon();
                this->p2_.cardsWon();   
            }
            return;
        }
        // Checking once again the match up between the cards.
        match = battle(this->p1_,this->p2_,card1,card2);
    }

    if(match==1){   //PLayer1 won.
    this->p1_.cardsWon();
    while(draws!=0){
        this->p1_.cardsWon();
        draws-=2;
    }
    this->last_turn= this->getTurn(this->p1_.getName(),card1)+
                    this->getTurn(this->p2_.getName(),card2)+
                    this->p1_.getName() + " won.\n";
    this->p1_.addWin();
    this->p2_.addLoss();                
    this->summary+=this->last_turn;  
    }
    else if(match==2){  //Player2 won.
        this->p2_.cardsWon();
        while(draws!=0){
            this->p2_.cardsWon();
            draws-=2;
        }
        this->last_turn= this->getTurn(this->p1_.getName(),card1)+
                        this->getTurn(this->p2_.getName(),card2)+
                        this->p2_.getName() + " won.\n";
        this->p2_.addWin();
        this->p1_.addLoss();                  
        this->summary+=this->last_turn;                             
    }
}
    
void Game::playAll(){
    while(this->p1_.stacksize()>0 ){
        playTurn();
    }
}
void Game::printLastTurn(){
    cout<< this->last_turn<<endl;

}
void Game::printLog(){
    cout<< this->summary<<endl;

}
void Game::printStats(){
   cout<< this->p1_.getName() +": "<<endl;
   cout<< "Wins: "+ to_string(this->p1_.getWin()) + "/ 26"<<endl;
   cout<< "Draws: "+ to_string(this->p1_.getDraw()) + "/ 26"<<endl; 
   cout<< "Losses: "+ to_string(this->p1_.getLoss()) + "/ 26"<<endl;
   cout<<endl;
   cout<< this->p2_.getName() +": "<<endl;
   cout<< "Wins: "+ to_string(this->p2_.getWin()) + "/ 26"<<endl;
   cout<< "Draws: "+ to_string(this->p2_.getDraw()) + "/ 26"<<endl;
   cout<< "Losses: "+ to_string(this->p2_.getLoss()) + "/ 26"<<endl;  

}
void Game::printWiner(){
    if(this->p1_.cardesTaken()>this->p2_.cardesTaken()){
        cout<<"Winner is: "+ this->p1_.getName()<<endl;
        return;
    }
    else if(this->p1_.cardesTaken()<this->p2_.cardesTaken()){
        cout<<"Winner is: "+ this->p2_.getName()<<endl;
        return;
    }
    else{
        cout<<"Winner is: DRAW"<<endl;
        return;
    }
}
