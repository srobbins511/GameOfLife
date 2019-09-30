#include <iostream>
#include <fstream>
#include <math.h>

class Board
{
    public:
        //variables
        char **myArr;
        int len;
        int width;
        int numElems;

        Board();
        Board(int gLen, int gWidth, int density);
        Board(Board* startBoard);
        ~Board();
        bool getElem(int index);
        void Flip(int index);
        int getLen();
        int getWidth();
        std::string printBoard();
};