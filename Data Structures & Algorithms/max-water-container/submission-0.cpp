class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l=0,r=n-1;
        int maxi = INT_MIN;
        while(l<r){
            int ar = min(heights[l],heights[r])*(r-l);
            maxi = max(ar,maxi);
            if(heights[l]<=heights[r]) l++;
            else r--;
        }
        return maxi;

    }
};
