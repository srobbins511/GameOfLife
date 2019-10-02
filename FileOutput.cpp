#include "FileOutput.h"

//class to write out to a file
//constructor opens the file in the append mode
FileOutput::FileOutput(std::string fileName)
{
    fname = fileName;
    myFile.open(fname, ios::app);
}

//push writes a string to the file
void FileOutput::Push(std::string content)
{
    myFile << content << endl;
}

//closes the file stream
void FileOutput::Close()
{
    myFile.close();
}

//closes and reopens the file stream to overwrite the file
void FileOutput::Clear()
{
    myFile.close();
    myFile.open(fname, ios::out);
}

//check to see if file was opened successfully
bool FileOutput::Check()
{
    if(myFile.is_open())
    {
        return true;
    }
    return false;
}