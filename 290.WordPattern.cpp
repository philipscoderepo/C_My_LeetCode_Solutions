#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    string str = "dog cat cat dog",
               pattern = "abba";
    int strLen = str.length(),
        pattLen = pattern.length();
    bool isSpace = false;

    int *iptr = new int[pattLen];
    string *sptr = new string[pattLen];

    //Get Pattern
    for(int i = 0; i < pattLen; i++)
    {
        string check = str.substr(i, i + 1);
    }

    //Check Pattern
    for(int i = 0; i < strLen; i++)
    {
        string check = str.substr(i, i + 1);

        if(check == " ")
        {

        }
    }

}
