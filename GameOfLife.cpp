#include <iostream>
#include <fstream>
#include <math.h>
#include "GameManager.h"

using namespace std;

int main(int argc, char** argv)
{
    GameManager *start = new GameManager();
    start -> play();
}