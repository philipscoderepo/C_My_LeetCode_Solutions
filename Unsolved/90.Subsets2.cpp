class Solution {
public:
    bool checkForDup(vector<vector<int>> subsets,vector<int> set){
        for(int i = 0; i < subsets.size(); i++){
            if(subsets[i].size() == set.size()){
                int subsetKey = 0, setKey = 0;

                for(int j = 0; j < set.size(); j++){
                    if(subsets[i][j] >= 0){
                        subsetKey = subsetKey + (subsets[i][j] * subsets[i][j]);
                    }else{
                        subsetKey = subsetKey + ((subsets[i][j] + 11) * (subsets[i][j] + 11));
                    }

                    if(set[j] >= 0){
                        setKey = setKey + (set[j] * set[j]);
                    }else{
                        setKey = setKey + ((set[j] + 11) * (set[j] + 11));
                    }

                }
                if(setKey == subsetKey){
                    return true;
                }
            }

        }
        return false;
    }

    vector<int> swap(vector<int> set){
        int temp = set[0];
        for(int i = 0; i < set.size() - 1; i++){
            set[i] = set[i + 1];
        }
        set[set.size()-1] = temp;

        return set;
    }

    vector<int> swapAtIndex(vector<int> set, int index1, int index2){
        int temp = set[index1];
        set[index1] = set[index2];
        set[index2] = temp;
        return set;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        //Empty set
        subsets.push_back(vector<int>());
        //Iterate for each number in the vector
        for(int i = 0; i < nums.size(); i++){
            vector<int> setO, setE, numsTemp;
            //Get the first number
            setO.push_back(nums[0]);
            if(!checkForDup(subsets, setO)){
                subsets.push_back(setO);
            }
            numsTemp = nums;
            for(int j = 1; j < nums.size(); j++){
                for(int l = 1; l < nums.size(); l++){
                    for(int k = 1; k < nums.size(); k++){
                        setO.push_back(numsTemp[k]);
                        if(!checkForDup(subsets, setO)){
                            subsets.push_back(setO);
                        }
                    }
                    if((l + 1) < nums.size()){
                        numsTemp = swapAtIndex(numsTemp, j, l + 1);
                    }
                    setO.clear();
                    setO.push_back(nums[0]);
                }
            }
            nums = swap(nums);
        }
        return subsets;

    }
};
