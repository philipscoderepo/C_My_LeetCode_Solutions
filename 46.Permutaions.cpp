#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> uniquePerm;
        vector<int> tempV1, tempV2;
        int tempI;
        for(int i=0; i<nums.size(); i++){
            tempV1 = nums;
            tempI = tempV1.at(0);
            tempV1.at(0) = tempV1.at(i);
            tempV1.at(i) = tempI;
            //Create Permutaions
            for(int j=0; j<nums.size(); j++){

                for(int k=0; k<2; k++){

                    //uniquePerm.push_back(tempV);
                }

            }
        }

        return uniquePerm;
}

int main(){

}
