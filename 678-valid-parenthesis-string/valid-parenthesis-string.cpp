class Solution {
public:
    bool checkValidString(string s) {
        int a=0,d=0;
        for(char c:s){
            if(c=='('){
                a++;
                d++;
            }
            else if(c==')'){
                if(a>0)a--;
                d--;
            }
            else {
                if(a>0)a--;
                if(d>=0)d++;
            }
            if(d<0)return false;
                
        }
        if(a==0)return true;
        
        return false;
    }
};