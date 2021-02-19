//
// Created by Luojia yan on 2021-02-07.
//

#include "Map.h"
using namespace std;
#include "iostream"
#include "MapDriver.h"

int mapDriver::main() {
    Map testMap = Map("test", 6, 7);
    Continent continent1 = Continent("Continent1" , 1);
    Continent continent2 = Continent("Continent2" , 2);
    Continent continent3 = Continent("Continent3" , 3);
    Continent continent4 = Continent("Continent4" , 4);
    Continent continent5 = Continent("Continent5" , 5);
    Continent continent6 = Continent("Continent6" , 6);

    testMap.AddContinent(&continent1);
    testMap.AddContinent(&continent2);
    testMap.AddContinent(&continent3);
    testMap.AddContinent(&continent4);
    testMap.AddContinent(&continent5);
    testMap.AddContinent(&continent6);

    /*
    helper.AddEdgesContinents(1,2);
    helper.AddEdgesContinents(2,3);
    helper.AddEdgesContinents(3,4);
    helper.AddEdgesContinents(4,1);
    helper.AddEdgesContinents(1,3);
     */


    Territory *T0 = new Territory("Territory1",1,1);
    Territory *T1 = new Territory("Territory2",2,1);
    Territory *T2 = new Territory("Territory3",3,2);
    Territory *T3 = new Territory("Territory4",4,3);
    Territory *T4 = new Territory("Territory5",5,4);
    Territory *T5 = new Territory("Territory6",6,5);
    Territory *T6 = new Territory("Territory7",7,6);

    T0->SetNumTroops("player1",1);
    T1->SetNumTroops("player2",2);
    T2->SetNumTroops("player3",3);
    T3->SetNumTroops("player4",4);

    T0->GetNumTroops("player1");
    T1->GetNumTroops("player2");
    T2->GetNumTroops("player3");
    T3->GetNumTroops("player4");
    T4->GetNumTroops("player1");
    T5->GetNumTroops("player2");
    T6->GetNumTroops("player3");

    continent1.AddTerritory(T0);
    continent1.AddTerritory(T1);
    continent2.AddTerritory(T2);
    continent3.AddTerritory(T3);
    continent4.AddTerritory(T4);
    continent5.AddTerritory(T5);
    continent6.AddTerritory(T6);

    testMap.AddEdgesCountry(T0, T1);
    testMap.AddEdgesCountry(T1, T2);
    testMap.AddEdgesCountry(T2, T3);
    testMap.AddEdgesCountry(T3, T4);
    testMap.AddEdgesCountry(T4, T5);
    testMap.AddEdgesCountry(T5, T6);

    testMap.PrintContinentMatrix();
    testMap.PrintTerritoryMatrix();

    testMap.Validate(&testMap);
    testMap.dfsValidate();

    return 0;

}
