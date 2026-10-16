class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n=sequence.size();
        int m=word.size();
        string temp=word;
        int count=0;
        while(sequence.find(temp)!=string::npos){
            count++;
            temp+=word;
        }
        return count;
    }
};