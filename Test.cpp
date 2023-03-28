#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/card.hpp"
#include "sources/game.hpp"
#include "sources/player.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test 1"){
    Player p1("Dor");
    Player p2("Nor");
    Game game(p1,p2);
    CHECK_THROWS(game.printLastTurn());
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printStats());
    CHECK_THROWS(game.printWiner());
    CHECK_NOTHROW(game.playAll());
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printStats());
}
TEST_CASE("Test 1"){
    Player p1("Dor");
    Player p2("Nor");
    Game game(p1,p2);
    CHECK_NOTHROW(game.playTurn());
    CHECK(p1.stacksize()<25);
    CHECK(p2.stacksize()<25);
    bool flag=(p1.cardesTaken()>0) || (p2.cardesTaken()>0);
    CHECK(flag);
    for(int i=0;i<10;i++)
    {
        CHECK_NOTHROW(game.playTurn());
    }
    CHECK(p1.stacksize()<15);
    CHECK(p2.stacksize()<15);
    CHECK_NOTHROW(game.playAll());
    CHECK(p1.stacksize()==0);
    CHECK(p2.stacksize()==0);
    Player p3("Mor");
    Game game2(p1,p3);
    CHECK_THROWS(game2.printWiner());
    CHECK_NOTHROW(game2.playAll());
    CHECK(p1.stacksize()==0);
    CHECK(p3.stacksize()==0);
}
