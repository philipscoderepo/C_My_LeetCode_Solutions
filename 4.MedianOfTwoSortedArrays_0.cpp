class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ///Merged will store the items sorted from both arrays
        vector<int> merged;
        ///Get the sizes
        int size_i=nums1.size(),
        size_j=nums2.size();
        ///Determine the max amount of times the while loop will iterate
        int i=0, j=0, counter = 0,
        maxIter = size_i + size_j;

        ///Merge the arrays
        while(counter < maxIter){
            if(i>=size_i && j<size_j){
                merged.push_back(nums2.at(j));
                j++;
            }
            else if(j>=size_j && i<size_i){
                merged.push_back(nums1.at(i));
                i++;
            }
            else{
                if(nums1.at(i) > nums2.at(j)){
                    merged.push_back(nums2.at(j));
                    j++;
                }
                else{
                    merged.push_back(nums1.at(i));
                    i++;
                }
            }
            counter++;
        }

        int size_m = merged.size();
        double median;

        ///Determine if the number of items in the array is even or odd
        if(size_m%2==0){
            median = (merged.at(size_m/2-1)+merged.at(size_m/2))/2.0;
        }
        else{
            median = merged.at(size_m/2);
        }

        return median;
    }
};
