#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
class FileInput
{
    public:
        //variables
        std::string content;
        int length;
        int width;
        bool success;

        //constructor
        FileInput(std::string fname);
        
        //methods
        bool completed();
        int getLength();
        int getWidth();
        std::string getContent();
        void Format();
        int atoi(std::string num);
};