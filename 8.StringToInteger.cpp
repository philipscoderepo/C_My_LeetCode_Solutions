#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    string str = "name";

    int strLen = str.length();
    bool isNegative = false;
    for(int i = 0; i < strLen; i++)
    {
        string check = str.substr(i, i + 1);

        if(check == "-")
        {
            isNegative = true;
        }

        if(isdigit(check))

    }



}
