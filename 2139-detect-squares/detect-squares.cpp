
class DetectSquares {
    unordered_map<int, unordered_map<int, int>> cnt;

public:
    DetectSquares() {}

    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        // Choose the second corner on the same vertical line.
        for (auto& [y2, freq] : cnt[x]) {
            if (y2 == y) continue;

            int d = y2 - y;

            // Other two corners on the right.
            ans += freq * cnt[x + d][y] * cnt[x + d][y2];

            // Other two corners on the left.
            ans += freq * cnt[x - d][y] * cnt[x - d][y2];
        }

        return ans;
    }
};
