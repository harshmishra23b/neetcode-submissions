class Solution {
public: 
    int isPossible(vector<int>& piles,int rate){
        int r = 0;
        int m = piles.size();
        for(int i=0;i<m;i++){
            r += (piles[i] + rate - 1) / rate;
        }
        return r;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = -1;
        for(int i=0;i<n;i++){
            if(piles[i]>high) high = piles[i];
        }
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            int hourly = isPossible(piles,mid);
            if(hourly<=h){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
