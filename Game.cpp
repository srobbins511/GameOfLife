#include "Game.h"
#include <iostream>

//Rule Code List
// 0: Classic Mode
// 1: Mirror Mode
// 2: Donut Mode


using namespace std;

//generic base constructor
Game::Game()
{
    GenCount = 0;
    ruleCode = 0;
    len = 10;
    width = 10;
    gameBoard = new Board();
    nextBoard = new Board();
}

//constructor used when generating a game based on user command line input
Game::Game(int rules, int gLen, int gWidth, double density)
{
    GenCount = 0;
    ruleCode = rules;
    len = gLen;
    width = gWidth;
    gameBoard = new Board(len, width, density);
    nextBoard = new Board(len, width);
}

//constructor used when generating a game based on a user provided file
Game::Game(int rules, int gLen, int gWidth, std::string content)
{
    GenCount = 0;
    ruleCode = rules;
    len = gLen;
    width = gWidth;
    cout << "Creating Game Board" << endl;
    gameBoard = new Board(len, width, content);
    cout << "created Game Board" << endl;
    nextBoard = new Board(len, width);
}

//destructor
Game::~Game()
{
    delete gameBoard;
    delete nextBoard;
}

//check the survival of a unit based on its neighbors
bool Game::CheckSurvival(int i, int j)
{
    int neighborCount = 0;
    int posCode = 0;
    //PositionType
    //true: it is not a corner or edge
    //false: it is a corner or edge
    bool PositionType = CheckPosition(i,j);

    //the check method called is based on the mode user inputed
    switch(ruleCode)
    {
        case 0:
            if(PositionType)
            {
                neighborCount = StandardCheck(i,j);
            }
            else{
                neighborCount = ClassicCheck(i,j);
            }
            break;
        case 1:
            if(PositionType)
            {
                neighborCount = StandardCheck(i,j);
            }
            else
            {
                neighborCount = MirrorCheck(i,j);
            }
            break;
        case 2:
            if(PositionType)
            {
                neighborCount = StandardCheck(i,j);
            }
            else
            {
                neighborCount = DonutCheck(i,j);
            }
            break;
    }

    if(neighborCount <=1)
    {
        return false;
    }
    else if(neighborCount == 2)
    {
        return gameBoard->getElem(i,j);
    }
    else if(neighborCount == 3)
    {
        return true;
    }
    return false;
}

//the check method for all values that do not reside on an edge of the grid
int Game::StandardCheck(int i, int j)
{
    int neighborCount = 0;
    for(int k = -1; k<=1; ++k)
    {
        for(int l = -1; l<=1; ++l)
        {
            if(k==0 && j==0)
            {
                continue;
            }
            else if(gameBoard->getElem(i+k,j+l))
            {
                ++neighborCount;
            }
        }
    }
    return neighborCount;
}

//check to see where on the grid a given i,j value resides
bool Game::CheckPosition(int i, int j)
{
    bool posCode = false;
    if( i != 0 && i != (len-1) && j !=0 && j != (width-1) )
    {
       posCode = true;
    }
    return posCode;
}


//Logic to check to survival of locations at corners and edges in classic mode
int Game::ClassicCheck(int i, int j)
{
    int neighborCount = 0;
    for(int k = -1; k<=1; ++k)
    {
        for(int l = -1; l<=1; ++l)
        {
            //if a corner iterate over
            if( (k==0 && j==0) || ((i+k)<0) || ((i+k)>=len) || ((j+l)<0) || ((j+l)>=width))
            {
                continue;
            }
            else if(gameBoard->getElem(i+k,j+l))
            {
                //otherwise increment neighbor count
                ++neighborCount;
            }
        }
    }
    return neighborCount;
}

//Logic to check to survival of locations at corners and edges in Mirro mode
int Game::MirrorCheck(int i, int j)
{
    int neighborCount = 0;
    //check to see if the given element is a corner
    if( (i == 0 && j ==0 ) || (i==0 && j == width-1) || (i == len-1 && j ==0) || (i ==len-1 && j == width-1) )
    {
        if(gameBoard->getElem(i,j))
        {
            neighborCount+=3;
        }                
    }
    //loop through all the neighbors
    for(int k = -1; k<=1; ++k)
    {
        for(int l = -1; l<=1; ++l)
        {
            //if a corner iterate past
            if((k==0 && j==0) || ((i+k)<0) || ((i+k)>=len) || ((j+l)<0) || ((j+l)>=width))
            {
                continue;
            }
            //otherwise check the element
            if(gameBoard->getElem(i+k,j+l))
            {
                //if on an edge count twice
                if(i+k == 0 || i+k == len-1 || j+l == 0 || j+l == width-1)
                {
                    neighborCount+=2;
                }
                else
                {
                    //otherwise increment once
                    ++neighborCount;
                }
            }
        }
    }
    //return the number of neighbors
    return neighborCount;
}

//The method to check corners and edges for Donut Mode
int Game::DonutCheck(int i, int j)
{
    int neighborCount = 0;
    for(int k = -1; k<=1; ++k)
    {
        for(int l = -1; l<=1; ++l)
        {
            //if given value iterate past
            if((k==0 && j==0)) 
            {
                continue;
            }
            if( ((i+k)<0) || ((i+k)>=len) || ((j+l)<0) || ((j+l)>=width) )
            {
                //if on edge flip values that lie past edge to other edges of grid
                if(gameBoard->getElem(flipPosI(i+k), flipPosJ(j+l)) )
                {
                    ++neighborCount;
                }
            }
            else if(gameBoard->getElem(i+k,j+l))
            {
                ++neighborCount;
            }
        }
    }
    return neighborCount;
}

//if the given i value would refer to a value off the grid, flip it to refer to the last value on the opposite side
int Game::flipPosI(int posi)
{
    int i = posi;
    if(i < 0)
    {
        i = len-1;
    }
    else if(i >= len){
        i = 0;
    }
    return i;
}

//if the given j value refers to a location off the grid, flip it to refer to the last value on the opposite side
int Game::flipPosJ(int posj)
{
    int j = posj;
    if(j < 0)
    {
        j = width-1;
    }
    else if(j >= width){
        j = 0;
    }
    return j;
}

//simulate the results of one generation passing
void Game::NextGeneration()
{
    nextBoard = new Board(gameBoard);
    for(int i = 0; i<len; ++i)
    {
        for(int j = 0; j<width; ++j)
        {
            nextBoard->Set(i,j,CheckSurvival(i,j));
        }
    }
    //flip the positions of the two boards
    Board *temp = gameBoard;
    gameBoard = nextBoard;
    nextBoard = temp;
}

//print out the current game board that is active
std::string Game::printBoard()
{
    return gameBoard->printBoard();
}

// compare the two boards together
//used to determine of the grids are stabalizing at specific patterns
bool Game::Compare()
{
    bool same = true;
    int iCountCur = 0;
    int iCountNext = 0;
    int jCountCur = 0;
    int jCountNext = 0;
    int *checksumsICur = new int[len];
    int *checksumsINext = new int[len];
    int *checksumsJCur = new int[width];
    int *checksumsJNext = new int[width];
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(gameBoard->getElem(i,j) != nextBoard->getElem(i,j))
            {
                same = false;
            }
            if(gameBoard->getElem(i,j))
            {
                iCountCur++;
            }
            if(nextBoard->getElem(i,j))
            {
                iCountNext++;
            }
        }
        checksumsICur[i] = iCountCur;
        checksumsINext[i] = iCountNext;
    }
    for(int j = 0; j < width; j++)
    {
        for(int i = 0; i < len; i++)
        {
            if(gameBoard->getElem(i,j))
            {
                jCountCur++;
            }
            if(nextBoard->getElem(i,j))
            {
                jCountNext++;
            }
        }
        checksumsJCur[j] = jCountCur;
        checksumsJNext[j] = jCountNext;
    }
    for(int i = 0; i < len; ++i)
    {
        if(checksumsICur[i] != checksumsINext[i])
        {
            same = false;
        }
    }
    for(int j = 0; j < width; ++j)
    {
        if(checksumsJCur[j] != checksumsJNext[j])
        {
            same = false;
        }
    }
    return same;
}