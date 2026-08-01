class Solution {
public:
    unordered_map<int,bool> dp;
    bool solve(int idx,string s,vector<string>& dict){
        int n = s.length();
        if(idx == n){
            return true;
        }
        if(dp.find(idx)!=dp.end()) return dp[idx];
        for(const string& w: dict){
            if(idx + w.length() <= n && s.substr(idx,w.length()) == w){
                if(solve(idx+w.length(),s,dict)){
                    dp[idx] = true;
                    return true;
                }
            }
        }
        dp[idx] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp[s.length()] = true;
        return solve(0,s,wordDict);
    }
};
