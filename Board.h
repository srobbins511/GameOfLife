#include <iostream>
#include <fstream>
#include <math.h>

class Board
{
    public:
        //variables
        bool **myArr;
        int len;
        int width;
        int numElems;

        Board();
        Board(int gLen, int gWidth, double density);
        Board(int gLen, int gWidth);
        Board(int gLen, int gWidth, std::string content);
        Board(Board* startBoard);
        ~Board();
        bool getElem(int iPos, int jPos);
        bool isEmpty();
        void Set(int i, int j, bool state);
        int getLen();
        int getWidth();
        std::string printBoard();
};