class Solution {
public:
    int maxArea(vector<int>& height) {

        int current_area = 0,
            up = 0,
            down = height.size()-1,
            max_area = 0;

        while(up < down){
            if(height.at(up) > height.at(down)){
                current_area = (height.at(up) - (height.at(up) - height.at(down))) * (down-up);
                //If the height at up is larger than down then decrement down
                down--;
            }
            else{
                current_area = (height.at(down) - (height.at(down) - height.at(up))) * (down-up);
                //If the height at down is larger than up then increment up
                up++;
            }

            if(current_area > max_area){max_area = current_area;}
        }

        return max_area;
    }

};
