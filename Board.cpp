#include "Board.h"

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

Board::Board(int gLen, int gWidth, int density)
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
    delete myArr;
}

//if value is X return true that the element at that location is alive
bool Board::getElem(int index)
{
    int i = index/width;
    int j = index%len;
    if(myArr[i][j] == 'X')
    {
        return true;
    }
    return false;
}

void Board::Flip(int index)
{
    int i = index/width;
    int j = index%len;
    if(myArr[i][j] == 'X')
    {
        myArr[i][j] = '-';
    }
    else
    {
        myArr[i][j] = 'X';
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
            temp+=myArr[i][j];
        }
        temp += "\n";
    }
    return temp;
}