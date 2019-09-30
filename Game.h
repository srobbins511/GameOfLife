#include <iostream>
#include <fstream>
#include <math.h>
#include "Board.h"



class Game
{
    public:
        int GenCount;
        int ruleCode;
        Board *gameBoard;
        Board *nextBoard;


        Game();
        Game(int rules);
        ~Game();

        bool CheckSurvival(int rule, int i, int j);
        void NextGeneration(int rule);
};