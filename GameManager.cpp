#include "GameManager.h"


using namespace std;

GameManager::GameManager()
{
    if(!UserInput())
    {
        exit(EXIT_FAILURE);
    }
}

GameManager::~GameManager()
{
    delete myGame;
    delete myFile;
}

void GameManager::play()
{
    for(int i = 0; i<10; i++)
    {
        cout << myGame->printBoard();
        myGame->NextGeneration();
    }
}

bool GameManager::getValues()
{
    bool exit = false;
    while(!exit)
    {
        cout << "Enter the Length: " << endl;
        cin >> len;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(30000, '\n');
            cout << "Incorrect Input" << endl;
        }
        else
        {
            exit = true;
        }
    }
    exit = false;
    while(!exit)
    {
        cout << "Enter the Width: " << endl;
        cin >> width;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(30000, '\n');
            cout << "Incorrect Input" << endl;
        }
        else
        {
            exit = true;
        }
    }
    exit = false;
    while(!exit)
    {
        cout << "Enter the Density as a value n where  n>=0 and n<=1: " << endl;
        cin >> density;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(30000, '\n');
            cout << "Incorrect Input" << endl;
        }
        else
        {
            exit = true;
        }
    }
}


bool GameManager::UserInput()
{
    std::string temp = "";
    bool exit = false;
    while(!exit)
    {
        cout << "To simulate Classic mode Enter C: \nTo simulate Mirror Mode Enter M \nTo simulate in Donut Mode Enter D: " << endl << endl;
        cin >> temp;

        if(temp == "C" || temp == "c")
        {
            exit = true;
            rules = 0;
        }
        else if(temp == "M" || temp == "m")
        {
            exit = true;
            rules = 1;
        }
        else if(temp == "D" || temp == "d")
        {
            exit = true;
            rules = 2;
        }
        else
        {
            cout << "Unrecognized Input" << endl;
        }
    }
    exit = false;

    while(!exit)
    {
        cout << "To start with a random configuration Enter R \nTo start with a map file Enter M: " << endl << endl;
        cin >> temp;

        if(temp == "M" || temp == "m")
        {
            bool complete = false;
            std::string fname;
            while(!complete)
            {
                cout << "enter the name of the file, if the file does not exist in the current directory enter the PATH with it: " << endl;
                cin >> fname;
                myFile = new FileInput(fname);
                if(myFile->completed())
                {
                    complete = true;
                }
                else{
                    cout << "File Error" << endl;
                    return false;
                }
            }
            cout << "Formatting called" << endl;
            myFile->Format();
            cout << "Formatting Finished" << endl;
            myGame = new Game(rules, myFile->getLength(), myFile->getWidth(), myFile->getContent());
            cout << "Game Created" << endl;
            exit = true;;
        }
        else if(temp == "R" || temp == "r")
        {
            getValues();
            myGame = new Game(rules, len, width, density);
            exit = true;
        }
        else
        {
            cout << "Unrecognized Input" << endl;
        }
    }
    exit = false;
    while(!exit)
    {
        cout << "Select Output Option: " << endl;
        cout << "  1. Pause between outputs, Outputs to Console" << endl;
        cout << "  2. Require Key Press Between outputs, Outputs to Console" << endl;
        cout << "  3. Output to File" << endl << endl;
        cout << "Enter the number of the Output Option: " << endl;
        cin >> temp;
        if(temp == "1")
        {
            exit = true;
            OutputCode = 1;
        }
        else if(temp == "2")
        {
            exit = true;
            OutputCode = 2;
        }
        else if(temp == "3")
        {
            exit = true;
            OutputCode = 3;
        }
        else{
            cout << "Incorrect Input" << endl;
        }
    }
    return true;
}
