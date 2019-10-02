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

int FileInput::atoi(std::string num)
{
    int number = 0;
    for(char c : num)
    {
        number*=10;
        if(c == '9')
        {
            number+=9;
        }
        else if(c == '8')
        {
            number+=8;
        }
        else if(c == '7')
        {
            number+=7;
        }
        else if(c == '6')
        {
            number+=6;
        }
        else if(c == '5')
        {
            number+=5;
        }
        else if(c == '4')
        {
            number+=4;
        }
        else if(c == '3')
        {
            number+=3;
        }
        else if(c == '2')
        {
            number+=2;
        }
        else if(c == '1')
        {
            number+=1;
        }
        else if(c == '0')
        {
            number+=0;
        }
    }
    return number;
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
    cout << content << endl;
    for(char c : content)
    {
        if(c=='|')
        {
            if(count == 1)
            {
                length = atoi(temp);
            }
            else if(count == 2)
            {
                width = atoi(temp);
            }
            else
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