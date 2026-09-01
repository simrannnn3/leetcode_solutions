class Solution {
public:

    struct State {
        int r, c;
        int mask;
        int energy;
        int moves;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int sr = -1, sc = -1;
        int litterCount = 0;

        vector<vector<int>> litterId(n, vector<int>(m, -1));

        // Find S and assign IDs to L
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        queue<State> q;

        // bestEnergy[r][c][mask]
        // maximum energy with which we have reached this state
        vector<vector<vector<int>>> bestEnergy(
            n,
            vector<vector<int>>(
                m,
                vector<int>(1 << litterCount, -1)
            )
        );

        // Starting state
        q.push({sr, sc, 0, energy, 0});
        bestEnergy[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            State curr = q.front();
            q.pop();

            // All litter collected
            if (curr.mask == fullMask) {
                return curr.moves;
            }

            // No energy
            if (curr.energy == 0) {
                continue;
            }

            for (int d = 0; d < 4; d++) {

                int nr = curr.r + dr[d];
                int nc = curr.c + dc[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                int newEnergy = curr.energy - 1;
                int newMask = curr.mask;

                // Collect litter
                if (classroom[nr][nc] == 'L') {
                    int id = litterId[nr][nc];
                    newMask |= (1 << id);
                }

                // Reset energy
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                // Dominance check
                if (newEnergy <= bestEnergy[nr][nc][newMask]) {
                    continue;
                }

                bestEnergy[nr][nc][newMask] = newEnergy;

                q.push({
                    nr,
                    nc,
                    newMask,
                    newEnergy,
                    curr.moves + 1
                });
            }
        }

        return -1;
    }
};