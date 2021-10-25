class Solution {
public:
    string frequencySort(string s) {
        int slen = s.length();
        int i, j;
        char temp;

        //Sort alphabetically
        for(i=1; i<slen; i++){
            j = i;
            while(j>0 && s[j] < s[j-1]){
                temp = s[j];
                s[j] = s[j-1];
                s[j-1] = temp;
                j--;
            }
        }

        vector<string> sort;
        sort.resize(slen);
        int add;
        j = 0;
        //Put similar letters into their own containers
        for(i=0; i<slen; i+=add, j++){
            add = 1;
            sort.at(j) += s[i];
            while(s[i] == s[i+add]){
                sort.at(j) += s[i+add];
                add++;
            }
        }

        //Sort the containers by their length
        string sTemp;
        for(i=1; i<slen; i++){
            j = i;
            while(j>0 && sort.at(j).length() > sort.at(j-1).length()){
                sTemp = sort.at(j);
                sort.at(j) = sort.at(j-1);
                sort.at(j-1) = sTemp;
                j--;
            }
        }

        //Create the string
        string sorted;
        for(i=0; i<sort.size(); i++){
            sorted += sort.at(i);
        }

        return sorted;
    }
};
