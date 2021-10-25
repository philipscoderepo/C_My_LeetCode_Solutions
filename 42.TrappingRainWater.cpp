class Solution {
public:
    int trap(vector<int>& height) {
        //Any size less than 3 cannot store water
        if(height.size() < 3){return 0;}

        int water_trapped=0,
            left=0,
            right=height.size()-1,
            left_max=height.at(left),
            right_max=height.at(right);

        while(right > left){
            if(height.at(right) > height.at(left)){
                left++;
                if(height.at(left) > left_max){
                    left_max = height.at(left);
                }
                else{
                    water_trapped += left_max - height.at(left);
                }
            }
            else{
                right--;
                if(height.at(right) > right_max){
                    right_max = height.at(right);
                }
                else{
                    water_trapped += right_max - height.at(right);
                }
            }
        }

        return water_trapped;
    }
};
