#include "Board.h"
#include <iostream>

using namespace std;


Board::Board()
{
    myArr = new char*[10];
    for(int i = 0; i < 10; ++i)
    {
        myArr[i] = new char[10];
    }
    len = 10;
    width = 10;
    numElems = len*width;
}

Board::Board(int gLen, int gWidth, double density)
{
    len = gLen;
    width = gWidth;
    numElems = len*width;
    myArr = new char*[len];
    for(int i = 0; i < len; ++i)
    {
        myArr[i] = new char[width];
    }
    //Code how to use density to create a random distribution of living locations
    for(int i = 0; i< len; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            double randA = rand()/(double)RAND_MAX;
            if(randA < density)
            {
                myArr[i][j] = 'X';
            }
            else{
                myArr[i][j] = '-';
            }
        }
    }
}

Board::Board(int gLen, int gWidth, std::string content)
{
    len = gLen;
    width = gWidth;
    myArr = new char*[len];
    for(int i = 0; i < len; ++i)
    {
        myArr[i] = new char[width];
    }
    int i = -1;
    int j = 0;
    for(char c : content)
    {
        if(c=='|')
        {
            i++;
            j = 0;
        }
        else if(c=='X' || c== '-')
        {
            myArr[i][j] = c;
            j++;
        }
        else
        {
            cout << "Unrecognized Symbol in initialization data" << endl;
        }
    }
}

Board::Board(int gLen, int gWidth)
{
    cout << "entered second game board constructor" << endl;
    len = gLen;
    width = gWidth;
    numElems = len*width;
    cout << "Creating second game board" << endl;
    myArr = new char*[len];
    for(int i = 0; i < len; ++i)
    {
        myArr[i] = new char[width];
    }
}

Board::Board(Board* startBoard)
{
    len = startBoard->len;
    width = startBoard->width;
    numElems = startBoard->numElems;
    myArr = new char*[len];
    for(int i = 0; i < len; ++i)
    {
        myArr[i] = new char[width];
    }
    for(int i = 0; i<len; ++i)
    {
        for(int j = 0; j<width; ++j)
        {
            myArr[i][j] = startBoard->myArr[i][j];
        }
    }
}

Board::~Board()
{
    for(int i=0; i<len; ++i)
    {
        delete [] myArr[i];
    }
    delete myArr;
}

//if value is X return true that the element at that location is alive
bool Board::getElem(int i, int j)
{
    if(myArr[i][j] == 'X')
    {
        return true;
    }
    return false;
}

bool Board::isEmpty()
{
    for(int i = 0; i < len; ++i)
    {
        for(int j = 0; i < width; ++j)
        {
            if(myArr[i][j] == 'X')
            {
                return false;
            }
        }
    }
    return true;
}

void Board::Set(int i, int j, bool state)
{
    if(state)
    {
        myArr[i][j] = 'X';
    }
    else
    {
        myArr[i][j]= '-';
    }
}

int Board::getLen()
{
    return len;
}

int Board::getWidth()
{
    return width;
}

std::string Board::printBoard()
{
    std::string temp = "";
    for(int i = 0; i<len; ++i)
    {
        for(int j = 0; j<width; ++j)
        {
            temp += myArr[i][j];
        }
        temp += "\n";
    }
    return temp;
}