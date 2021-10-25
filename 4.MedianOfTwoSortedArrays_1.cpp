class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int size_i=nums1.size(),
        size_j=nums2.size();
        int i=0, j=0;


        while(i<size_i && j<size_j){
            if(nums1.at(i) > nums2.at(j)){
                merged.push_back(nums2.at(j));
                j++;
            }
            else{
                merged.push_back(nums1.at(i));
                i++;
            }
        }

        if(i>=size_i && j<size_j){
            for(int k=j; k<size_j; k++){
                merged.push_back(nums2.at(k));
            }
        }
        else if(j>=size_j && i<size_i){
            for(int k=i; k<size_i; k++){
                merged.push_back(nums1.at(k));
            }
        }

        int size_m = merged.size();
        double median;
        if(size_m%2==0){
            median = (merged.at(size_m/2-1)+merged.at(size_m/2))/2.0;
        }
        else{
            median = merged.at(size_m/2);
        }

        return median;
    }
};
