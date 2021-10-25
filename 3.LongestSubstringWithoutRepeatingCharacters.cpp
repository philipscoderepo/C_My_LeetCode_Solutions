class Solution {
public:
    bool found_in_vector(vector<char> s, char ch){
        bool found = false;
        for(char c : s){
            if(c == ch){
                found = true;
            }
        }
        return found;
    }

    int lengthOfLongestSubstring(string s) {
        int len=0,
        longest = len;
        vector<char> check;

        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(!found_in_vector(check, s[j])){
                    check.push_back(s[j]);
                    len = check.size();
                }
                else{
                    break;
                }
            }
            check.clear();
            if(len>longest){longest=len;}
        }
        return longest;
    }
};
