#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
class FileOutput
{
    public:
        std::string fname;
        ofstream myFile;
        bool success;

        FileOutput(std::string fname);
        void Push(std::string content);
        void Clear();
        void Close();
        bool Check();
};