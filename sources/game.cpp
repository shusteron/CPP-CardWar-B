#include "game.hpp"
#include <stdio.h>
#include "card.hpp"
#include <iostream>
#include <cstdlib>

#define ACE 1
int draws=0;


namespace ariel{}
using namespace std;

Game::Game(Player &p1, Player &p2):
p1_(p1),p2_(p2)
{
    this->last_turn="";
    this->last_turn="";
    for(int i=0;i<53;i++){
        this->cards[i].setShape("");
        this->cards[i].setValue(0);

    }
    createDeck();
    splitDecks();
}

void Game::createDeck(){
    int index=1;
    for(int i=1;i<=13;i++){
        Card card("hearts",i);
        this->cards[index++]=card;
    }
    for(int i=1;i<=13;i++){
        Card card("clubs",i);
        this->cards[index++]=card;
    }
    for(int i=1;i<=13;i++){
        Card card("diamonds",i);
        this->cards[index++]=card;
    }
    for(int i=1;i<=13;i++){
        Card card("spades",i);
        this->cards[index++]=card;
    }
    shuffle();
}

void Game::shuffle(){
    Card shuffled_deck[53];
    int count_minus=0;
    int index=1;
    srand(time(nullptr));
    while(count_minus<52){
        // Generate random index number between 1 to 53. Without the 0 index.
        int random = rand()%53+1;  
        // Check if the card already exists in the shuffled deck. 
        if(shuffled_deck[index].getValue()!= this->cards[random].getValue() && shuffled_deck[index].getShape()!= this->cards[random].getShape()){
            shuffled_deck[index].setShape(this->cards[random].getShape());
            shuffled_deck[index].setValue(this->cards[random].getValue());
            index++;
            count_minus++;
        }
    }
    //Setting the original deck to the shuffeld one.
    for(int i=1;i<53;i++){
        this->cards[i].setShape(shuffled_deck[i].getShape());
        this->cards[i].setValue(shuffled_deck[i].getValue());

    }
}
void Game::splitDecks(){
    // Dealing the deck to the players.
    for(int i=1;i<53;i++){
        if(i<=26){
            this->p1_.addCard(this->cards[i]);
        }
        else{
            this->p2_.addCard(this->cards[i]);
        }
    }        
}
void Game::printDeck(){
    for(int i=1;i<53;i++){
        cout << to_string(this->cards[i].getValue()) + " of " + this->cards[i].getShape()<<endl;
    }
}
string Game::getTurn(string name, Card card){
    
    return name + " played " + to_string(card.getValue()) + " of " + card.getShape()+".";

}

int Game::battle(Player p1, Player p2, Card card1, Card card2){
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
    if(&this->p1_ == &this->p2_){
        throw invalid_argument("received same player");
    }
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
        else{
            while(this->p1_.stacksize()>0){
                this->p1_.getCard();
                this->p2_.getCard();
                this->p1_.cardsWon();
                this->p2_.cardsWon();   
            }
            return;
        }
        match = battle(this->p1_,this->p2_,card1,card2);

    }

    if(match==1){
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
    else if(match==2){
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
//     playTurn();
//     playTurn();
//     playTurn();
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
