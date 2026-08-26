class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left=0;
        int mini=INT_MAX;
        int count=0;
        string ans="";
        for(int right=0;right<s.size();right++){
            if(s[right]=='1'){
                count++;
            }
            while(count>=k){
                int len=right-left+1;
                string curr=s.substr(left,len);
                if(len<mini){
                    mini=len;
                    ans=curr;
                }
                else if(len==mini && curr<ans){
                    ans=curr;
                }
                if(s[left]=='1'){
                    count--;
                }
                left++;
                
            }
            
        }
        return ans;
    }
};