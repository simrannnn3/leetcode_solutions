class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int ans=nums[r];
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]<=nums[r]){
                ans=min(ans,nums[m]);
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};