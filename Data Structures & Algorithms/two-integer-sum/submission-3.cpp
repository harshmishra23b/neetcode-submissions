class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int more = 0;
        for(int i=0;i<nums.size();i++){
            more = target - nums[i];
            if(mpp.find(more) != mpp.end()) return {mpp[more],i};
            mpp[nums[i]] = i;
        }

        return {};
    }
};
