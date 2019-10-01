#include "FileInput.h"
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

FileInput::FileInput(std::string fname)
{
    length = -1;
    width = -1;
    ifstream myFile(fname);
    std::string line = "";
    if(myFile.is_open())
    {
        while(myFile)
            {
                content += line + "|";
                myFile >> line;
            }
            myFile.close();
    }
    else
    {
        //set the flag bool variable to false
        success = false;
    }
    success = true;
}

FileInput::~FileInput()
{
}

bool FileInput::completed()
{
    int count = 0;
    for(char c: content)
    {
        if(c == '|')
        {
            ++count;
        }
        else if((c!= 'X' && c!= '-' ) && count >2)
        {
            cout << "Incorrect File Format" << endl;
            return false;
        }
    }
    cout << "Checked File First time" << endl;
    return success;
}

void FileInput::Format()
{
    cout << "Created variables started" << endl;
    int count = 0;
    std::string temp = "";
    std::string formattedContent = "";
    cout << "Created variables" << endl;
    for(char c : content)
    {
        if(c=='|')
        {
            if(count == 0)
            {
                cout<< temp << endl;
                length = 5;
            }
            else if(count == 1)
            {
                width = 7;
            }
            else if(count > 2)
            {
                temp += c;
                formattedContent += temp;
            }
            temp = "";
            ++count;
            continue;
        }
        else{
            temp += c;
        }
    }
    cout<< "Formatted Content : " << endl << formattedContent << endl;
    content = formattedContent;
}

int FileInput::getLength()
{
    return length;
}

int FileInput::getWidth()
{
    return width;
}

std::string FileInput::getContent()
{
    return content;
}