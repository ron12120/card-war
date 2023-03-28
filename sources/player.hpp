
#include <string>
#pragma once
using namespace std;
namespace ariel {
    class Player{
    string name;
    public:
        Player(string);
        Player();
        int stacksize();
        int cardesTaken(); 
    };
};
