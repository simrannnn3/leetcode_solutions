class Solution {
public:
    unordered_set<string>ans;
    void solve(string &s,string curr, int i,int left,int right,int rleft,int rright){
        if(i==s.size()){
            if(rleft==0 && rright==0 && left==right){
                ans.insert(curr);
            }
            return;
        }
        char c=s[i];
        if(c!='(' && c!=')'){
            solve(s,curr+c,i+1,left,right,rleft,rright);
            return;
        }
        if(c=='(' && rleft>0){
            solve(s,curr,i+1,left,right,rleft-1,rright);
        }
        if(c==')' && rright>0){
            solve(s,curr,i+1,left,right,rleft,rright-1);
        }
        if(c=='('){
            solve(s,curr+c,i+1,left+1,right,rleft,rright);
        }
        else{
            if(left>right){
                solve(s,curr+c,i+1,left,right+1,rleft,rright);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int rleft=0;
        int rright=0;
        for(char c:s){
            if(c=='(')rleft++;
            else if(c==')'){
                if(rleft>0)rleft--;
                else rright++;
            }
        }
        solve(s,"",0,0,0,rleft,rright);
        return vector<string>(ans.begin(),ans.end());
        
    }
};