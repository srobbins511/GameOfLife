#include <iostream>
#include <fstream>
#include <math.h>
#include "GameManager.h"

using namespace std;

int main(int argc, char** argv)
{
    std::string test = "";
    test += to_string(10);
    cout << test << endl;
    GameManager *start = new GameManager();
    start -> play();
}