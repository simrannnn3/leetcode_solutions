class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n));
        string ans="";
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            ans=s.substr(0,1);
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                ans=s.substr(i,2);
            }
        }
        for(int i=2;i<n;i++){
            for(int j=0;j+i<n;j++){
                int k=j+i;
                if(s[j]==s[k] && dp[j+1][k-1]){
                    dp[j][k]=true;
                    ans=s.substr(j,k-j+1);
                }
            }
        }
        return ans;

    }
};