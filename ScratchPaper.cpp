#include <iostream>
#include <vector>

using namespace std;

bool check(char c, string s, int left){
    if(s[left+1] == '(' || s[left+1] == '{' || s[left+1] == '['){
        if(!check(s[left+1], s, left+1)){
            return false;
        }
    }
    else if((s[left] == '(' && s[left+1] == ')') ||
           (s[left] == '[' && s[left+1] == ']') ||
           (s[left] == '{' && s[left+1] == '}')){

        return true;
    }
}


int main(){
    bool is_valid=false;

    string s = "({[]})";

    cout << check(s[0], s, 0);
}
