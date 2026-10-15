class Solution {
public:
    int expand(int l,int r, string &s){
        int ans=0;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
            ans++;
        }
        return ans;
    }
    int countSubstrings(string s) {
         int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=expand(i,i,s);
            ans+=expand(i,i+1,s);
        }
        
        return ans;
        
    }
};