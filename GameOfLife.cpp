#include <iostream>
#include <fstream>
#include <math.h>
#include "GameManager.h"

using namespace std;

//main method
//calls the Game manager
int main(int argc, char** argv)
{
    std::string test = "";
    test += to_string(10);
    cout << test << endl;
    GameManager *start = new GameManager();
    start -> play();
    delete start;
    return 0;
}