#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> points;
        bool exit = false;
        for(int i=0; i<nums.size()-1 && !exit; i++){
            for(int j=i+1; j<nums.size() && !exit; j++){
                if((nums.at(i) + nums.at(j)) == target){
                    points.push_back(i);
                    points.push_back(j);
                    exit = true;
                }
            }
        }
        return points;
    }
};

int main()
{
    vector<int> nums = {2,3,6};
    int target = 6;
}

