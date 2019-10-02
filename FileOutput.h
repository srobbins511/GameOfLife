#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//class to write to a file
class FileOutput
{
    public:
        //variables
        std::string fname;
        ofstream myFile;
        bool success;

        //constructor
        FileOutput(std::string fname);

        //methods
        void Push(std::string content);
        void Clear();
        void Close();
        bool Check();
};