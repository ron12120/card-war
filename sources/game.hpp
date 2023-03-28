#include "player.hpp"
#include <string>
#include <iostream>


namespace ariel {
    class Game{
    Player player1;
    Player player2;
    public:
        Game(Player,Player);
        Game();
        void static playTurn();
        void static printLastTurn();
        void static playAll();
        void static printWiner();
        void static printLog();
        void static printStats();
    };
};