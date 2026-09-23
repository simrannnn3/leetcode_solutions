class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(int s:nums){
            sum+=s;
        }
        int rem=sum-x;
        if (rem < 0) return -1;
        int maxi=INT_MIN;
        sum=0;
        int l=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>rem){
                sum-=nums[l];
                l++;
            }
            if(sum==rem){
                maxi=max(maxi,right-l+1);
            }
        }
        if(maxi==INT_MIN)return -1;
        return nums.size()-maxi;
    }
};