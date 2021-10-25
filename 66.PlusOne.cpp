#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        unsigned int lastIndex = digits.size() - 1;
        bool isNine;

        if(digits[lastIndex] == 9)
        {
            isNine = true;
            digits.push_back(0);

           unsigned int index = lastIndex;

            while(isNine)
            {

                if(digits[index] == 9)
                {

                    digits[index] = 0;
                }
                else
                {
                    digits[index] += 1;
                    isNine = false;
                }
                index--;
            }
            if(digits[0] == 0)
            {
                digits[0] = 1;
            }
        }
        else
        {
            digits[digits.size() - 1] += 1;
        }

        return digits;
    }
};

int main()
{
        vector<int> digits = {9};
        int lastIndex = digits.size() - 1;
        bool isNine;

        if(digits[lastIndex] == 9)
        {
            isNine = true;
            digits.push_back(0);

            int index = lastIndex;

            while(isNine)
            {

                if(digits[index] == 9)
                {

                    digits[index] = 0;
                }
                else
                {
                    digits[index] += 1;
                    isNine = false;
                }
                index--;
            }
            if(digits[0] == 0)
            {
                digits[0] = 1;
            }
        }
        else
        {
            digits[digits.size() - 1] += 1;
        }

        for(unsigned int i = 0; i < digits.size(); i++)
        {
            cout << digits[i] << " ";
        }

}
