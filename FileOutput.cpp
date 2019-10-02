#include "FileOutput.h"


FileOutput::FileOutput(std::string fileName)
{
    fname = fileName;
    myFile.open(fname, ios::app);
}

void FileOutput::Push(std::string content)
{
    myFile << content << endl;
}

void FileOutput::Close()
{
    myFile.close();
}

void FileOutput::Clear()
{
    myFile.close();
    myFile.open(fname, ios::out);
}

bool FileOutput::Check()
{
    if(myFile.is_open())
    {
        return true;
    }
    return false;
}