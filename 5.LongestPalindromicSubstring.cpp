class Solution {
public:
    string longestPalindrome(string s) {
        ///Store the length in the first index and the starting index in the second
        int longest_even[2]={0,0},
            longest_odd[2]={0,0},
            len=0,
            start_index=0;

        //If the string is less than 2 characters there isn't any work needed
        if(s.length() < 2){return s;}

        ///Check for an even numbered palindrome
        for(int i=1; i<s.length(); i++){
            len = 1;
            if(s[i-1] == s[i]){
                //Right and left keep track of the current position in the string
                int right = i+1,
                    left = i-2;
                //Set the start and the length
                start_index = i-1;
                //The length will always be 2 or more in the case of an even palindrome
                len=2;
                while(left >= 0 && s[left] == s[right]){
                    start_index = left;
                    len+=2;
                    right++;
                    left--;
                }
            }
            if(len > longest_even[0]){
                longest_even[0] = len;
                longest_even[1] = start_index;
            }
        }

        ///Reset the starting position
        start_index=0;

        ///Check for an odd numbered palindrome
        for(int i=1; i<s.length(); i++){
            len = 1;
            if(s[i-1] == s[i+1]){
                //Right and left keep track of the current position in the string
                int right = i+2,
                    left = i-2;
                //Set the start and the length
                start_index = i-1;
                //The length will always be 3 or more in the case of an odd palindrome
                len=3;

                while(left >= 0 && s[right] == s[left]){
                    start_index--;
                    len+=2;
                    right++;
                    left--;
                }

            }
            if(len > longest_odd[0]){
                longest_odd[0] = len;
                longest_odd[1] = start_index;
            }
        }

        string longest_pal;

        if(longest_odd[0] > longest_even[0]){longest_pal = s.substr(longest_odd[1], longest_odd[0]);}
        else{longest_pal = s.substr(longest_even[1], longest_even[0]);}

        return longest_pal;

    }
};
