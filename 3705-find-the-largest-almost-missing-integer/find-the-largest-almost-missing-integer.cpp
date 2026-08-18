class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int maxi=-1;
        int m=nums.size();
        unordered_map<int,int>mp;
        for(int n:nums){
            maxi=max(maxi,n);
            mp[n]++;
        }
        if(k==m)return maxi;
        else if(k==1){
            maxi=-1;
            for(int i=0;i<m;i++){
                if(mp[nums[i]]==1 && nums[i]>maxi){
                    maxi=nums[i];
                }
            
            }
            return maxi;
        }
        else{
            if(mp[nums[0]]>1 && mp[nums[m-1]]>1){
                return -1;
            }else{
                if(mp[nums[0]]>1 && mp[nums[m-1]]<=1)return nums[m-1];
                else if(mp[nums[0]]<=1 && mp[nums[m-1]]>1) return nums[0];
                else return max(nums[0],nums[m-1]);
            }
        }
        return -1;
    }
};