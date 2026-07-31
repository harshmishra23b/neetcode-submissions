class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n);
        vector<int> pref(n);
        vector<int> op(n);
        pref[0] = nums[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]*nums[i];
        }

        suf[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] = suf[i+1]*nums[i];
        }
        for(int i=0;i<n;i++){
            int left = (i==0)?1:pref[i-1];
            int right = (i==n-1)?1:suf[i+1];
            op[i] = left*right;
        }

        return op;
    }
};
