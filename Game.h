#include <iostream>
#include <fstream>
#include <math.h>
#include "Board.h"


//class used to perfrom many of the functions needed for game of life
class Game
{
    public:
    //variables
        int GenCount;
        int ruleCode;
        int len;
        int width;
        double density;
        Board *gameBoard;
        Board *nextBoard;
        
        //constructors
        Game();     //basic constructor for a game object
        Game(int rules, int gLen, int gWidth, double density);      //constructor for a game object based on given rules, as well as size and density for the board
        Game(int rules, int length, int width, std::string content);    //constructor for a game object based on given rules, as well as size and a string to base first board off of
        
        //destructor
        ~Game();

        //methods
        std::string printBoard();   //print out the board that 
        bool CheckSurvival( int i, int j);      //check the survival of a unit based on the units around it
        bool CheckPosition(int i, int j);       //checks where a unit is located on the grid, returns true if the unit is not located on a corner or edge
        int StandardCheck(int i, int j);        //checks the units around a given unit based on a supplied index, used to check locations that are not on edges
        int MirrorCheck(int i, int j);          //checks the neighbors of a unit on an edge or corner in mirror mode
        int flipPosI(int i);               //flips the position a given i value to the other end of the grid, used in donut mode
        int flipPosJ(int j);               //flips the position a given j value to the other end of the grid, used in donut mode
        int ClassicCheck(int i, int j);     //checks the neighbors of a unit at an edge or corner in classic mode
        int DonutCheck(int i, int j);          //checks the neighbors of a unit at an edge or corner in donut mode
        void NextGeneration();                  //simulates which units will die or survive into the next generation
        bool Compare();             //compares the two boards together, used for determining stability
};