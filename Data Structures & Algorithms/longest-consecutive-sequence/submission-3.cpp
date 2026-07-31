class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int res = 0;
        for(auto it:st){
            if(!st.count(it-1)){
                int curr = it;
                int len = 1;
                while(st.count(curr+1)){
                    curr++;
                    len++;
                }

                res = max(len,res);
            }
        }
        return res;
    }
};
