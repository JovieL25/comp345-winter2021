//
// Created by Bowen Yang on 2021/1/30.
//
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <random>
#include <iterator>
#include <map>
#include "Cards.h"


using namespace std;

Card::Card(CardType type,std::string name,int number_of_army,int number_of_movement,int buildCity,int elixers,int
            kill_army,int fly_ability,int victory_point,int build_ability,int move_ability,int immune_to_attack,bool
           one_vp_for_night,bool one_vp_for_cursed,bool one_vp_for_arcane,bool one_vp_for_ancient,bool one_vp_for_dire,bool
           one_vp_for_forest,bool one_vp_3_coins,bool one_vp_for_fly,bool OR_CARD) :type(type),name(name),number_of_army
           (number_of_army)
           ,number_of_movement(number_of_movement),buildCity(buildCity),elixers(elixers),kill_army(kill_army),
           fly_ability(fly_ability),victory_point(victory_point),build_ability(build_ability),move_ability
           (move_ability),immune_to_attack(immune_to_attack),one_vp_for_night(one_vp_for_night),one_vp_for_cursed
           (one_vp_for_cursed),one_vp_for_arcane(one_vp_for_arcane),one_vp_for_ancient(one_vp_for_ancient),
           one_vp_for_dire(one_vp_for_dire),one_vp_for_forest(one_vp_for_forest),one_vp_3_coins(one_vp_3_coins),
           one_vp_for_fly(one_vp_for_fly),OR_CARD(OR_CARD){
//    std::cout<<"card: "+name+" is created!"<<endl;
}

Card::Card(const Card& card){
    type=card.type;
    name=card.name;
    number_of_army=card.number_of_army;
    number_of_movement=card.number_of_movement;
    buildCity=card.buildCity;
    elixers=card.elixers;
    kill_army=card.kill_army;
    fly_ability=card.fly_ability;
    victory_point=card.victory_point;
    build_ability=card.build_ability;
    move_ability=card.move_ability;
    immune_to_attack=card.immune_to_attack;
    one_vp_for_night=card.one_vp_for_night;
    one_vp_for_cursed=card.one_vp_for_cursed;
    one_vp_for_arcane=card.one_vp_for_arcane;
    one_vp_for_ancient=card.one_vp_for_ancient;
    one_vp_for_dire=card.one_vp_for_dire;
    one_vp_for_forest=card.one_vp_for_forest;
    one_vp_3_coins=card.one_vp_3_coins;
    one_vp_for_fly=card.one_vp_for_fly;
    OR_CARD=card.OR_CARD;
}
//to string method
ostream &operator<<(ostream& output, const Card& card) {
    output<<"card name: "+card.name<<endl;
    if (card.number_of_army>0){
        output<<"can build army: "<<card.number_of_army<<endl;
    }
    if (card.number_of_movement>0){
        output<<"can move: "<<card.number_of_movement<<endl;
    }
    if (card.buildCity>0){
        output<<"build one city"<<endl;
    }
    if (card.elixers>0){
        output<<"elixers"<<card.elixers<<endl;
    }
    if (card.kill_army>0){
        output<<"can kill army: "<<card.kill_army<<endl;
    }
    if (card.fly_ability>0){
        output<<"wings"<<endl;
    }
    if (card.victory_point>0){
        output<<"has victory point: "<<card.victory_point<<endl;
    }
    if (card.build_ability>0){
        output<<"build one more army"<<endl;
    }
    if (card.move_ability>0){
        output<<"one more movement"<<endl;
    }
    if (card.immune_to_attack>0){
        output<<"immune to attack"<<endl;
    }
    if (card.one_vp_for_night){
        output<<"one victory point for each night card"<<endl;
    }
    if (card.one_vp_for_cursed){
        output<<"one victory point for each cursed card"<<endl;
    }
    if (card.one_vp_for_arcane){
        output<<"one victory point for each arcane card"<<endl;
    }
    if (card.one_vp_for_ancient){
        output<<"one victory point for each ancient card"<<endl;
    }
    if (card.one_vp_for_dire){
        output<<"one victory point for dire night card"<<endl;
    }
    if (card.one_vp_for_forest){
        output<<"one victory point for each forest card"<<endl;
    }
    if (card.one_vp_3_coins){
        output<<"one victory point for every 3 coins"<<endl;
    }
    if (card.one_vp_for_fly){
        output<<"one victory point for each wing"<<endl;
    }
    if (card.OR_CARD){
        output<<"This is a cord with OR, you need to choose the action later."<<endl;
    }
//    output<<endl;
    return output;
}
Card& Card::operator=(const Card& card) {
    this->type=card.type;
    this->name=card.name;
    this->number_of_army=card.number_of_army;
    this->number_of_movement=card.number_of_movement;
    this->buildCity=card.buildCity;
    this->elixers=card.elixers;
    this->kill_army=card.kill_army;
    this->fly_ability=card.fly_ability;
    this->victory_point=card.victory_point;
    this->build_ability=card.build_ability;
    this->move_ability=card.move_ability;
    this->immune_to_attack=card.immune_to_attack;
    this->one_vp_for_night=card.one_vp_for_night;
    this->one_vp_for_cursed=card.one_vp_for_cursed;
    this->one_vp_for_arcane=card.one_vp_for_arcane;
    this->one_vp_for_ancient=card.one_vp_for_ancient;
    this->one_vp_for_dire=card.one_vp_for_dire;
    this->one_vp_for_forest=card.one_vp_for_forest;
    this->one_vp_3_coins=card.one_vp_3_coins;
    this->one_vp_for_fly=card.one_vp_for_fly;
    this->OR_CARD=card.OR_CARD;
    return *this;
}
Deck::Deck() {
    cout<<"default 4 players deck:"<<endl;
    deckVector = new std::vector<Card> ();
    deckVector->emplace_back(Card(arcane,"Arcane Sphinx",3,4,0,0,0,1,0,0,0,0, false, false, false, false, false,
                                  false, false, false, true));
    deckVector->emplace_back(Card(arcane,"Arcane Temple",0,3,0,0,0,0,0,0,0,0, false, false, false, false, false,
                                  false, false, false, false));


    // using built-in random generator:
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deckVector->begin(), deckVector->end(), g);
}


Deck::Deck(int number_of_player) {
    deckVector = new std::vector<Card> ();
    if (number_of_player==2){
        cout<<"Two players deck:"<<endl;
        deckVector->emplace_back(Card(arcane,"Arcane Sphinx",3,4,0,0,0,1,0,0,0,0, false, false, false, false, false,
                                      false, false, false, true));
        deckVector->emplace_back(Card(arcane,"Arcane Temple",0,3,0,0,0,0,0,0,0,0, false, false, false, false, false,
                                      false, false, false, false));
        deckVector->emplace_back(Card(noble,"Noble Unicorn",1,4,0,0,0,0,0,0,0,0, false, false, false, false, false,
                                      false, false, false, false));
        deckVector->emplace_back(Card(dire,"Dire Dragon",3,0,0,0,1,1,0,0,0,0, false, false, false, false, false,
                                      false, false, false, false));
        deckVector->emplace_back(Card(night,"Night Wizard",3,0,0,0,1,0,0,0,0,0, true, false, false, false, false,
                                      false, false, false, false));
        deckVector->emplace_back(Card(dire,"Dire Ogre",0,2,0,0,0,0,0,0,0,0, false, false, false, false, false,
                                      false, true, false, false));
        deckVector->emplace_back(Card(forest,"Forest Tree Toron",0,0,1,0,0,0,0,0,0,0, false, false, false, false,
                                      false,false, false, false, false));
        deckVector->emplace_back(Card(emptyKind,"Lake",2,3,0,0,0,0,0,0,0,0, false, false, false, false,
                                      false,false, false, false, true));

    }
    if(number_of_player==3){
        cout<<"Three players deck:"<<endl;
        deckVector->emplace_back(Card(arcane,"Arcane Sphinx",3,4,0,0,0,1,0,0,0,0, false, false, false, false, false,
                                      false, false, false, true));
        deckVector->emplace_back(Card(arcane,"Arcane Temple",0,3,0,0,0,0,0,0,0,0, false, false, false, false, false,
                                      false, false, false, false));
        deckVector->emplace_back(Card(noble,"Noble Unicorn",1,4,0,0,0,0,0,0,0,0, false, false, false, false, false,
                                      false, false, false, false));
        deckVector->emplace_back(Card(dire,"Dire Dragon",3,0,0,0,1,1,0,0,0,0, false, false, false, false, false,
                                      false, false, false, false));

    }
    if(number_of_player==4){
        cout<<"Four players deck:"<<endl;
        deckVector->emplace_back(Card(arcane,"Arcane Sphinx",3,4,0,0,0,1,0,0,0,0, false, false, false, false, false,
                                      false, false, false, true));
        deckVector->emplace_back(Card(arcane,"Arcane Temple",0,3,0,0,0,0,0,0,0,0, false, false, false, false, false,
                                      false, false, false, false));

    }

    // using built-in random generator:
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deckVector->begin(), deckVector->end(), g);

}

Deck::~Deck() {
    delete deckVector;
    deckVector = nullptr;
}

Deck::Deck(const Deck& deck) {
    this->deckVector = new vector<Card>(*(deck.deckVector));
}

Deck& Deck::operator=(const Deck& deck) {
    this->deckVector = new std::vector<Card>(*(deck.deckVector));
    return *this;
}

ostream &operator<<(ostream &output, const Deck& deck) {
    for(int i=0; i<deck.deckVector->size(); i++){
        output << deck.deckVector->at(i)<<endl;
    }
    return output;
}

std::vector<Card>* Deck::getDeckVector() {
    return deckVector;
}

Card Deck::draw() {
    if (!(getDeckVector()->empty()))
    {
        Card card = getDeckVector()->back();
        getDeckVector()->pop_back();
        return card;
    }
    else{
        //cout<<"no more card in the Deck!"<<endl;
        Card lastcard(emptyKind,"NoMoreCards",0,0,0,0,0,0,0,0,0,0, false, false, false, false, false, false, false,
                      false, false);
        return lastcard;
    }
}


Hand::Hand(Deck* deck) {
    handVector = new std::vector<Card>();
    //draw 6 cards in the begining of the game
    handVector->emplace_back(deck->draw());
    handVector->emplace_back(deck->draw());
    handVector->emplace_back(deck->draw());
    handVector->emplace_back(deck->draw());
    handVector->emplace_back(deck->draw());
    handVector->emplace_back(deck->draw());
}

Hand::~Hand() {
    delete handVector;
    handVector = nullptr;
}

Hand::Hand(const Hand& hand) {
    this->handVector = new std::vector<Card>(*(hand.handVector));
}

Hand& Hand::operator=(const Hand& hand) {
    this->handVector = new std::vector<Card>(*(hand.handVector));
    return *this;
}

std::ostream &operator<<(ostream &output, const Hand& hand) {
    map<int, int> moneyMap{ {0,0},{1,1},{2,1},{3,2},{4,2},{5,3} };
    for(int i=0; i<hand.handVector->size(); i++){
        output << "Card "<<i+1<<" this card takes "<<moneyMap[i]<<" coins "<<endl;
        output << hand.handVector->at(i)<< endl;
    }
    return output;
}

std::vector<Card>* Hand::getHandVector() {
    return handVector;
}

//return pointer Card


Card * Hand::exchange( int card_number, P p, Deck *deck) {
    for(int i=0; i<handVector->size(); i++){
        if (card_number-1==i){
            Card * card= new Card(handVector->at(i));
            handVector->erase (handVector->begin()+i);
            //draw a new card from deck
            handVector->emplace_back(deck->draw());
            p.Pay();
            return card;
        }
    }

    return nullptr;
}

/*
Card Hand::exchange( int card_number, P p, Deck *deck) {
    for(int i=0; i<handVector->size(); i++){
        if (card_number-1==i){
            Card card=handVector->at(i);
            handVector->erase (handVector->begin()+i);
            //draw a new card from deck
            handVector->emplace_back(deck->draw());
            p.Pay();
            return card;
        }
    }
    throw 1;
}
*/
