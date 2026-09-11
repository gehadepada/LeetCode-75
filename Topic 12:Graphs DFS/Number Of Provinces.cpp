class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int cur) {
        vis[cur] = true;
        for (int j = 0; j < adj[cur].size(); j++) {
            if (adj[cur][j] == 1 && vis[j] == false) {
                dfs(adj, vis, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                dfs(isConnected, vis, i);
                res++;
            }
        }
        return res;
    }
};