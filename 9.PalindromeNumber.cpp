class Solution {
public:
    bool isPalindrome(int number) {
        bool flag = false;
        long reverseNumber = 0,
                remainder,
                temp = number;

        if(number > -1)
        {
            while(temp != 0)
            {
                remainder = temp%10;
                reverseNumber = reverseNumber*10 + remainder;
                temp /= 10;
            }

            if(number == reverseNumber)
            {
                flag = true;
            }

        }

        return flag;
    }
};

