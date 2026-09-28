class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxi=0;
        for(char c:s){
            maxi=max(maxi,count);
            if(c=='('){
                count++;
            }else if(c==')'){
                count--;
            }
        }
        return maxi;
    }
};