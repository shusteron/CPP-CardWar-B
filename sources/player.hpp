#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>
#include <vector>
#include "card.hpp"

namespace ariel{}
using namespace std;
class Player{
    private:
    string name;
    vector<Card> deck;
    int won;
    int wins,losses,draws;
    
    
    public:
        Player(){}
        Player(string name);
        int stacksize();
        int cardesTaken();
        void addCard(Card card);
        Card getCard();
        int peek();
        void cardsWon();
        string getName();
        Card back();
        void addWin();
        void addDraw();
        void addLoss();
        int getWin();
        int getDraw();
        int getLoss();
        vector<Card> getDeck();


};
#endif
