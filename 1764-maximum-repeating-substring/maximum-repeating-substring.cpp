class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.length();
        int m = word.length();
        
        vector<int> dp(n + 1, 0);
        int ans = 0;

        for (int i = m; i <= n; ++i) {
            // Check if the substring ending at i matches the word
            if (sequence.substr(i - m, m) == word) {
                dp[i] = dp[i - m] + 1;
                ans = max(ans, dp[i]);
            }
        }
        return ans;
}
};