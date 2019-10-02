#include "GameManager.h"
#include "stdlib.h"
#include <chrono>
#include <thread>


using namespace std;
using namespace std::chrono_literals;

//construct the game manager object
//calls the user input method to determine if the users enter the correct input
//if not exits
GameManager::GameManager()
{
    simCount = 0;
    if(!UserInput())
    {
        exit(EXIT_FAILURE);
    }
}

//destructo
GameManager::~GameManager()
{
    delete myGame;
    delete myFile;
}

//manages of the logic of how the game is simulated
//what output is used is also controled by this
void GameManager::play()
{
    int count = 1;
    while(!Similarity())
    {
        switch(OutputCode)
        {
            case 1:
                cout << count << endl;
                cout << myGame->printBoard() <<endl;
                myGame->NextGeneration();
                std::this_thread::sleep_for(2s);
                break;
            case 2:
                cout << count << endl;
                cout << myGame->printBoard() <<endl;
                myGame->NextGeneration();
                cin.get();
                break;
            case 3:
                myGame->NextGeneration();
                FileOutput *outPut = new FileOutput(fname);
                if(count == 1)
                {
                    outPut -> Clear();
                }
                if(!outPut->Check())
                {
                    cout << "File not correctly opened" << endl;
                    exit(EXIT_FAILURE);
                }
                std::string temp = "" + count;
                outPut->Push(temp);
                outPut->Push(myGame->printBoard());
                delete outPut;
                break;
        }
        count++;
    }
}

//check to see if the grids have stabalized
//if the grids are two similar too many times in a row, simulation ends
bool GameManager::Similarity()
{
    if(myGame->Compare())
    {
        simCount++;
    }
    else
    {
        simCount = 0;
    }

    if(simCount >=5)
    {
        return true;
    }
    return false;
}

//gets values needed by the user and insures that they are correct
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

//get the user input on how the game should be run and if the user provides a file it is read here
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
            while(!complete)
            {
                cout << "enter the name of the file, if the file does not exist in the current directory enter the PATH with it: " << endl;
                cin >> fname;
                //opens and reads the file in the constructor of the FileInput Class
                myFile = new FileInput(fname);
                //checks to see if file was correctly read from
                if(myFile->completed())
                {
                    complete = true;
                }
                else{
                    cout << "File Error" << endl;
                    return false;
                }
            }
            myFile->Format();
            myGame = new Game(rules, myFile->getLength(), myFile->getWidth(), myFile->getContent());
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
            bool finish = false;
            cout << "enter the name of the file, if the file does not exist in the current directory enter the PATH with it: " << endl;
            cin >> fname;
        }
    }
    return true;
}
