#include <iostream>
#include <fstream>
#include <math.h>
#include "Board.h"



class Game
{
    public:
        int GenCount;
        int ruleCode;
        int len;
        int width;
        double density;
        Board *gameBoard;
        Board *nextBoard;

        Game();
        Game(int rules, int gLen, int gWidth, double density);
        Game(int rules, int length, int width, std::string content);
        ~Game();

        std::string printBoard();
        bool CheckSurvival( int i, int j);
        bool CheckPosition(int i, int j);
        int StandardCheck(int i, int j);
        int MirrorCheck(int i, int j);
        int flipPosI(int i);
        int flipPosJ(int j);
        int ClassicCheck(int i, int j);
        int DonutCheck(int i, int j);
        void NextGeneration();
        bool Compare();
};