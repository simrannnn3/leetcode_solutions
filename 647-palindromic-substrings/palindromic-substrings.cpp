class Solution {
public:
    bool palindrome(int l,int r,string &s){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string sub=s.substr(i,j-i+1);
                if(palindrome(0,sub.size()-1,sub)){
                    ans++;
                }
            }
        }
        return ans;
    }
};