//So this solution works but, when the number an int can store is a limited size,
//the variable will run out of space

class Solution {
public:
    int reverse(int x) {
        int reverseNumber = 0,
              remainder;

        while(x != 0)
            {
                remainder = x%10;
                reverseNumber = reverseNumber*10 + remainder;
                x /= 10;
            }

        return reverseNumber;
    }
};

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

            rev = rev * 10 + pop;
        }
        return rev;
    }
};
