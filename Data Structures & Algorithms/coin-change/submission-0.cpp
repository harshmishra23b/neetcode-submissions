class Solution {
public:
    int solve(int idx,vector<int>& coins,int tar,vector<vector<int>>& dp){
        int n = coins.size();
        if(idx == n-1){
            if(tar%coins[idx] == 0) return (tar/coins[idx]);
            else return 1e9;
        }
        if(dp[idx][tar]!=-1) return dp[idx][tar];
        int take = 1e9;
        if(coins[idx]<=tar)
             take = 1+solve(idx,coins,tar-coins[idx],dp);
        int skip = solve(idx+1,coins,tar,dp);
        dp[idx][tar] = min(take,skip);
        return dp[idx][tar];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans =  solve(0,coins,amount,dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
