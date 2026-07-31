class Solution {
public:
    bool isPalindrome(string s) {
        for(auto &it:s){
            it = tolower(it);
        }
        string copy="";
        for(auto it:s){
            if(isalnum(it)) copy += it; 
        }
        int n = copy.size();
        int i =0;
        while(i<=n/2){
            if(copy[i]!= copy[n-i-1]){
                return false;
            }
            i++;
        }
        return true;
    }
};
