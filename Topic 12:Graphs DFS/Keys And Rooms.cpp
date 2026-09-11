class Solution {
public:
    void dfs(vector<vector<int>>&adj , vector<bool>&vis ,int cur)
    {
        vis[cur]=true;
        for(auto i : adj[cur])
        {
            if(vis[i]==false){
            dfs(adj , vis , i);
            }
        }
        

    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n , false);
        dfs(rooms , vis , 0 );
        for(int i =0 ; i< n ;i ++)
        {
            if(vis[i] == false)
            {
                return false;
            }
        }
        return true;
        
        
    }
};