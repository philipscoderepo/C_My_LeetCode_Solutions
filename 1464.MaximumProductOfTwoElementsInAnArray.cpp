#include <iostream>
#include <vector>
using namespace std;

/**
Given the array of integers nums, you will choose two different indices i and j of that array.
Return the maximum value of (nums[i]-1)*(nums[j]-1).
**/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNum,
        big = 0,
        secBig = 0;

        for(unsigned int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > secBig)
            {
                if(nums[i] > big)
                {
                    secBig = big;
                    big = nums[i];
                }
                else
                {
                    secBig = nums[i];
                }
            }
        }

        maxNum = (big - 1) * (secBig - 1);

        return maxNum;
    }
};









int main()
{
    vector<int> nums = {10,2,5,2};
    int maxNum,
        big = 0,
        secBig = 0;

        for(unsigned int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > secBig)
            {
                if(nums[i] > big)
                {
                    secBig = big;
                    big = nums[i];
                }
                else
                {
                    secBig = nums[i];
                }
            }
        }

        maxNum = (big - 1) * (secBig - 1);
        cout << maxNum;
}
