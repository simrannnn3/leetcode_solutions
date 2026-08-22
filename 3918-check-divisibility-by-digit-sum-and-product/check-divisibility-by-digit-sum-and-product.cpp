class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int sum1=0;
        int pro=1;
        while(n>0){
            int digit=n%10;
            sum1+=digit;
            pro*=digit;
            n/=10;
        }
        if(num%(sum1+pro)==0)return true;
        return false;
    }
};