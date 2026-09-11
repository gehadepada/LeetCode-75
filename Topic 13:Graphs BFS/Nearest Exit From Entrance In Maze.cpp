class Solution {
public:
    int bfs(vector<vector<char>>& maze, vector<int>& entrance)
    {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<pair<int,int> , int>>q;
        q.push({{entrance[0] , entrance[1]},0});
       map<pair<int,int>, int> vis;
        vis[{entrance[0] , entrance[1]}]++;
        pair<int,int>enter={entrance[0],entrance[1]};
        
        int step = 0 ;
        while(!q.empty())
        {
            pair< pair<int,int>,int>node=q.front();
             pair<int,int>node2={q.front().first.first , q.front().first.second};
            if((enter !=node2)&& maze[node.first.first][node.first.second] =='.' &&(node.first.first == n-1 ||node.first.first == 0 || node.first.second == m-1 || node.first.second == 0 ))
            {
              
                return node.second;
            }
                      vis[{node.first.first , node.first.second}]++;
            q.pop();
                 
                if(vis.count({node.first.first+1 , node.first.second}) == 0 && node.first.first+1<n && maze[node.first.first+1][node.first.second] =='.')
                {
                    q.push({{node.first.first+1 , node.first.second},node.second+1});
                    vis[{node.first.first+1 , node.first.second}]++;
                   
                }
                if(vis.count({node.first.first-1 , node.first.second})== 0 &&node.first.first -1 >= 0 &&maze[node.first.first-1][node.first.second] =='.')
                {
                     q.push({{node.first.first- 1 , node.first.second} ,node.second+1});
                     vis[{node.first.first-1 , node.first.second}]++;
                 

                }
                if(vis.count({node.first.first , node.first.second-1})== 0 && node.first.second -1 >= 0 &&maze[node.first.first][node.first.second-1] =='.' )
                {
                     q.push({{node.first.first , node.first.second-1} , node.second+1});
                     vis[{node.first.first , node.first.second-1}]++;
                    
 
                }
                if(vis.count({node.first.first , node.first.second+1}) == 0  && node.first.second  + 1 <m&&maze[node.first.first][node.first.second+1] =='.')
                {
                     q.push({{node.first.first , node.first.second+1},node.second+1});
                     vis[{node.first.first , node.first.second+1}]++;
           

                }
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        return bfs(maze , entrance);
        
    }
};