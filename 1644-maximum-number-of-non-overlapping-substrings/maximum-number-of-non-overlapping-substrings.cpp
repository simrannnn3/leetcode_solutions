class Solution {
public:
    void dfs1(int v,
              vector<vector<bool>>& graph,
              vector<bool>& vis,
              stack<int>& st) {

        vis[v] = true;

        for (int i = 0; i < 26; i++) {
            if (graph[v][i] && !vis[i])
                dfs1(i, graph, vis, st);
        }

        st.push(v);
    }

    void dfs2(int v,
              vector<vector<bool>>& graph,
              vector<int>& comp,
              int id,
              vector<int>& outDegree) {

        if (comp[v] == -1) {
            comp[v] = id;

            for (int i = 0; i < 26; i++) {
                if (graph[i][v]) {
                    dfs2(i, graph, comp, id, outDegree);
                }
            }
        }
        else if (comp[v] != id) {
            outDegree[comp[v]]++;
        }
    }

    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> first(26, INT_MAX);
        vector<int> last(26, -1);
        vector<bool> exist(26, false);

        vector<vector<int>> prefix(n + 1, vector<int>(26));

        for (int i = 0; i < n; i++) {

            prefix[i + 1] = prefix[i];

            int c = s[i] - 'a';

            prefix[i + 1][c]++;

            first[c] = min(first[c], i);
            last[c] = max(last[c], i);

            exist[c] = true;
        }

        vector<vector<bool>> graph(26, vector<bool>(26, false));

        for (int i = 0; i < 26; i++) {

            if (!exist[i]) continue;

            for (int j = 0; j < 26; j++) {

                if (prefix[last[i] + 1][j] - prefix[first[i]][j] > 0)
                    graph[i][j] = true;
            }
        }

        stack<int> st;
        vector<bool> vis(26, false);

        for (int i = 0; i < 26; i++) {
            if (exist[i] && !vis[i])
                dfs1(i, graph, vis, st);
        }

        vector<int> comp(26, -1);
        vector<int> outDegree(26);

        int id = 0;

        while (!st.empty()) {

            int v = st.top();
            st.pop();

            if (comp[v] == -1) {
                dfs2(v, graph, comp, id, outDegree);
                id++;
            }
        }

        vector<string> ans;

        for (int cur = id - 1; cur >= 0; cur--) {

            if (outDegree[cur] == 0) {

                int L = INT_MAX;
                int R = -1;

                for (int c = 0; c < 26; c++) {

                    if (comp[c] == cur) {

                        L = min(L, first[c]);
                        R = max(R, last[c]);
                    }
                }

                ans.push_back(s.substr(L, R - L + 1));
            }
        }

        return ans;
    }
};