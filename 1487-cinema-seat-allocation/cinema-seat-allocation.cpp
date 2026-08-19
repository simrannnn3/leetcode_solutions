class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int>mp;
        for(auto t:reservedSeats){
            int row=t[0];
            int seat=t[1];
            mp[row] |=(1<<seat);
        }
        int left   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        int ans = (n - mp.size()) * 2;
        for(auto &[row,mask]:mp){
            bool canLeft   = (mask & left) == 0;
            bool canMiddle = (mask & middle) == 0;
            bool canRight  = (mask & right) == 0;
            if(canLeft && canRight){
                ans+=2;
            }else if(canLeft || canMiddle || canRight)ans+=1;

        }
        return ans;
    }
};