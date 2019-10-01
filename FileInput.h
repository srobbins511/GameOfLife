#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
class FileInput
{
    public:
        std::string content;
        int length;
        int width;
        bool success;

        FileInput(std::string fname);
        ~FileInput();
        bool completed();
        int getLength();
        int getWidth();
        std::string getContent();
        void Format();
};