class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>a;
        vector<pair<int,int>>b;
        int n=img1.size();
        int m=img1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(img1[i][j]==1)a.push_back({i,j});
                if(img2[i][j]==1)b.push_back({i,j});
            }
        }
        map<pair<int,int>,int>freq;
        int ans=0;
        for(auto [r,c]:a){
            for(auto [x,y]:b){
                int dx=r-x;
                int dy=c-y;
                freq[{dx,dy}]++;
                ans=max(ans,freq[{dx,dy}]);
            }
        }
        return ans;
    }
};