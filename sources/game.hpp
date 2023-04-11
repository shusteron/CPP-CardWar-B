#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include <vector>
#include "card.hpp"

namespace ariel{}
using namespace std;

class Game{
    private:
    Player &p1_;
    Player &p2_;
    Card cards[53];
    string summary;
    string last_turn;
    int matches;
    void shuffle();
    void createDeck();
    void printDeck();
    void splitDecks();
    string getTurn(string name, Card card);
    int battle(Player p1, Player p2, Card card1, Card card2);


    

    public:
    
    //Game(){}
    Game(Player &p1, Player &p2);

    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

};
#endif
