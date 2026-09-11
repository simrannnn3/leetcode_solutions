class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=-1;
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]>=target){
                if(nums[m]==target)start=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        int end=-1;
        l=0,r=nums.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]<=target){
                if(nums[m]==target)end=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return {start,end};
    }
};