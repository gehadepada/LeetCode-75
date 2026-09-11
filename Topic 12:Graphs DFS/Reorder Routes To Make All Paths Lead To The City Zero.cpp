class Solution {
public:
 int res =0;
 void dfs(vector<vector<pair<int,int>>>&adj , vector<bool>&vis ,int cur ){
    vis[cur] = true;
       for(auto& [i,sign] : adj[cur])
        {
            if(vis[i]==false){
             res+=sign;
            dfs(adj , vis , i);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool>vis(n , false);
        vector<vector<pair<int,int>>>adj(n);
        for(int i =0 ;i < connections.size() ;i ++)
        {
            adj[connections[i][0]].push_back( {connections[i][1] , 1 });
            adj[connections[i][1]].push_back( {connections[i][0] , 0 });
        }

        for (int i = 0; i < n; i++) { 
            dfs(adj, vis, i );
        }
        return res;
        
    }
};