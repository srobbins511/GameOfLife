#include <iostream>
#include <fstream>
#include <math.h>
#include "Game.h"
#include "FileInput.h"
#include "FileOutput.h"


class GameManager
{
    public:
        //variables
        Game *myGame;
        int rules;
        int OutputCode;
        int len;
        int width;
        double density;
        int simCount;
        FileInput *myFile;
        std::string fname;

        //constructor    
        GameManager();

        //destructor
        ~GameManager();

        //methods
        void play();
        bool Similarity();
        bool UserInput();
        bool getValues();
};