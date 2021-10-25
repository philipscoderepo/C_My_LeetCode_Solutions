class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length(),
        lastWord = 0;
        bool wordFound = false;
    
        for(int i = len - 1; i >= 0; i--){
            if(s[i] != ' '){
                wordFound = true;
            }
            
            if(s[i] != ' ' && wordFound){
                lastWord++;
            }else if(wordFound){
                break;
            }
        }
        
        return lastWord;
    }
};