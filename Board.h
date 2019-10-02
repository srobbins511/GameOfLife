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

        //constructors
        Board();
        Board(int gLen, int gWidth, double density);    //contructs a board based on given size and density values
        Board(int gLen, int gWidth);        //constructs a board based on given size constraints
        Board(int gLen, int gWidth, std::string content);       //constructs a board based on a given string as well as given length and widths
        Board(Board* startBoard);       //copy constructor for a board

        //destructor
        ~Board();

        //methods
        bool getElem(int iPos, int jPos);   //returns a bool true or false based on the element in the list
        bool isEmpty();     //checks to see if the array is empty
        void Set(int i, int j, bool state);     //changes the value of a specified member of a board based on a bool input
        int getLen();       //return the length of the board
        int getWidth();     //return the width of the board
        std::string printBoard();       //print the board out as a string
};