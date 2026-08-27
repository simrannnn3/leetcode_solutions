class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26);
        for (char c : s)
            cnt[c - 'a']++;

        string ans;

        // Try to follow target exactly.
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (cnt[x] > 0) {
                // Matching target[i] keeps us as small as possible.
                ans += target[i];
                cnt[x]--;
                continue;
            }

            // Can't match target[i].
            // Try the smallest available character greater than it.
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans += char('a' + c);
                    cnt[c]--;

                    // Once we're greater, make the suffix minimal.
                    for (int k = 0; k < 26; k++) {
                        ans += string(cnt[k], char('a' + k));
                    }

                    return ans;
                }
            }

            // No greater character works here.
            // Backtrack to an earlier matched position.
            break;
        }

        // Restore matched characters from right to left and
        // try to increase one of them.
        while (!ans.empty()) {
            char old = ans.back();
            ans.pop_back();

            cnt[old - 'a']++;

            int x = old - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans += char('a' + c);
                    cnt[c]--;

                    // Smallest possible suffix.
                    for (int k = 0; k < 26; k++) {
                        ans += string(cnt[k], char('a' + k));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};