class Solution {
public:
    bool isValid(int num){
        if(num>=10 && num<=26) return true;
        else return false;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = (s[0]!='0');
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0') dp[i] += dp[i-1];
            int num = stoi(s.substr(i-2,2));
            if(isValid(num)) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
