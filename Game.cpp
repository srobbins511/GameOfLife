#include "Game.h"
#include <iostream>

//Rule Code List
// 0: Classic Mode
// 1: Mirror Mode
// 2: Donut Mode


//ToDO List
//fix all the pointer errors when using getElems();
//initialize the rest of the checking methods and their logic

using namespace std;

Game::Game()
{
    GenCount = 0;
    ruleCode = 0;
    len = 10;
    width = 10;
    gameBoard = new Board();
    nextBoard = new Board();
}

Game::Game(int rules, int gLen, int gWidth, double density)
{
    GenCount = 0;
    ruleCode = rules;
    len = gLen;
    width = gWidth;
    gameBoard = new Board(len, width, density);
    nextBoard = new Board(len, width);
}

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
    cout << "created game Board" << endl;
}

Game::~Game()
{
    delete gameBoard;
    delete nextBoard;
}
bool Game::CheckSurvival(int i, int j)
{
    int neighborCount = 0;
    int posCode = 0;
    //PositionType
    //true: it is not a corner or edge
    //false: it is a corner or edge
    bool PositionType = CheckPosition(i,j);

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

bool Game::CheckPosition(int i, int j)
{
    bool posCode = false;
    if( i != 0 && i != (len-1) && j !=0 && j != (width-1) )
    {
       posCode = true;
    }
    return posCode;
}


//Logic to check to survival of locations at corners and edges in standard mode
int Game::ClassicCheck(int i, int j)
{
    int neighborCount = 0;
    for(int k = -1; k<=1; ++k)
    {
        for(int l = -1; l<=1; ++l)
        {
            if( (k==0 && j==0) || ((i+k)<0) || ((i+k)>=len) || ((j+l)<0) || ((j+l)>=width))
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

int Game::MirrorCheck(int i, int j)
{
    int neighborCount = 0;
    if( (i == 0 && j ==0 ) || (i==0 && j == width-1) || (i == len-1 && j ==0) || (i ==len-1 && j == width-1) )
    {
        if(gameBoard->getElem(i,j))
        {
            neighborCount+=3;
        }                
    }
    for(int k = -1; k<=1; ++k)
    {
        for(int l = -1; l<=1; ++l)
        {
            if((k==0 && j==0) || ((i+k)<0) || ((i+k)>=len) || ((j+l)<0) || ((j+l)>=width))
            {
                continue;
            }
            if(gameBoard->getElem(i+k,j+l))
            {
                if(i+k == 0 || i+k == len-1 || j+l == 0 || j+l == width-1)
                {
                    neighborCount+=2;
                }
                else
                {
                    ++neighborCount;
                }
            }
        }
    }
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
            if((k==0 && j==0)) 
            {
                continue;
            }
            if( ((i+k)<0) || ((i+k)>=len) || ((j+l)<0) || ((j+l)>=width) )
            {
                if(gameBoard->getElem(flipPosI(i+k), flipPosJ(j+l)) )
                {
                    ++neighborCount;
                }
            }
            if(gameBoard->getElem(i+k,j+l))
            {
                ++neighborCount;
            }
        }
    }
    return neighborCount;
}

int Game::flipPosI(int i)
{
    if(i < 0)
    {
        i = len-1;
    }
    else if(i >= len){
        i = 0;
    }
    return i;
}

int Game::flipPosJ(int j)
{
    if(j < 0)
    {
        j = width-1;
    }
    else if(j >= width){
        j = 0;
    }
    return j;
}

void Game::NextGeneration()
{
    for(int i = 0; i<len; ++i)
    {
        for(int j = 0; j<width; ++j)
        {
            nextBoard->Set(i,j,CheckSurvival(i,j));
        }
    }
    Board *temp = gameBoard;
    gameBoard = nextBoard;
    nextBoard = temp;
}

std::string Game::printBoard()
{
    return gameBoard->printBoard();
}