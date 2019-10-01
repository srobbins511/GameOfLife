#include <iostream>
#include <fstream>
#include <math.h>
#include "Game.h"
#include "FileInput.h"


class GameManager
{
    public:
        Game *myGame;
        int rules;
        int OutputCode;
        int len;
        int width;
        double density;
        FileInput *myFile;

        GameManager();
        ~GameManager();
        void play();
        bool Stabalized();
        bool UserInput();
        bool getValues();
};