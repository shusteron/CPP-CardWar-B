#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include <vector>
#include <array>
#include "card.hpp"

namespace ariel{}
using namespace std;

class Game{
    private:
    Player &p1_;
    Player &p2_;
    vector<Card> cards;
    string summary;
    string last_turn;
    void shuffle();
    void createDeck();
    void splitDecks();
    string getTurn(string name, Card card);
    int battle(Player pl1, Player pl2, Card card1, Card card2);


    

    public:
    
    Game(Player &pl1, Player &pl2);

    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

};
#endif
