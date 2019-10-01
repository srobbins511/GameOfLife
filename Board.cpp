#include "Board.h"
#include <iostream>

using namespace std;


Board::Board()
{
    myArr = new bool*[10];
    for(int i = 0; i < 10; ++i)
    {
        myArr[i] = new bool[10];
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
    myArr = new bool*[len];
    for(int i = 0; i < len; ++i)
    {
        myArr[i] = new bool[width];
    }
    //Code how to use density to create a random distribution of living locations
    
}

Board::Board(int gLen, int gWidth, std::string content)
{
    len = gLen;
    width = gWidth;
    cout << " create array" << endl;
    myArr = new bool*[len];
    cout << "start making array 2d" << endl;
    for(int i = 0; i < len; ++i)
    {
        myArr[i] = new bool[width];
    }
    int i = 0;
    int j = 0;
    for(char c : content)
    {
        if(c=='|')
        {
            ++i;
        }
        else if(c == 'X'|| c == '-')
        {
            myArr[i][j++] = true;
            cout << c << endl;
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
    myArr = new bool*[len];
    for(int i = 0; i < len; ++i)
    {
        myArr[i] = new bool[width];
        for(int j = 0; j < width; ++j)
        {
            myArr[i][j] = false;
        }
    }
}

Board::Board(Board* startBoard)
{
    len = startBoard->len;
    width = startBoard->width;
    numElems = startBoard->numElems;
    myArr = new bool*[len];
    for(int i = 0; i < len; ++i)
    {
        myArr[i] = new bool[width];
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
    delete myArr;
}

//if value is X return true that the element at that location is alive
bool Board::getElem(int i, int j)
{
    return myArr[i][j];
}

bool Board::isEmpty()
{
    for(int i = 0; i < len; ++i)
    {
        for(int j = 0; i < width; ++j)
        {
            if(myArr[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void Board::Set(int i, int j, bool state)
{
    myArr[i][j]= state;
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
            if(myArr[i][j])
            {
                temp+='X';
            }
            else
            {
                temp+='-';
            }
        }
        temp += "\n";
    }
    return temp;
}