//
// Created by Jingchao Zhang on 2/26/2021.
//

#ifndef COMP345_WINTER2021_GAME_H
#define COMP345_WINTER2021_GAME_H
#include "Map.h"
#include "Player.h"
#include "Cards.h"
#include <vector>
#include <string>

class Game {
public:
    Game();
    ~Game();
    bool start();
    bool startup();
    void play();
    void computeScore();
    void claimWinner();

private:
    int numOfPlayer;
    Map* map;
    vector<Player*> players;
    Deck* deck;
    Hand* hand;
    int coinSupply;
    int startRegionId;
    unordered_map<string, int> armies; // color -> the number of armies supplied on the table
    unordered_map<string, int> cities; // color -> the number of cities supplied on the table
    static const int CARD_COSTS[6];
    static const int CARD_COSTS_SIZE;
    vector<string> COLORS;
    vector<int> order;   // [2, 3, 1] means player with id 2 move first, then player with id 3, then id 1;
    void createPlayers();
    bool selectMap();
    void selectNumberOfPlayers();
    void createDeck();
    void createArmiesAndCities();
    void printSixCards();
    bool selectStartingRegion();
    void bid();
    Player* getPlayerById(int id);
    bool criteriaA(int regionId);
    bool criteriaB(int regionId);
    Card* selectCard(Player* currentPlayer);
    void computeMapScore();
    void computeAbilityScore();
    void computeElixirScore();
    void displayWinner(Player* player);
    void printComponents();
};


#endif //COMP345_WINTER2021_GAME_H