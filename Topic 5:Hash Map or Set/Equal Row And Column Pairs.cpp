class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string , int >row,col;
        int n = grid.size();
        int m = grid[0].size();
        string y ="";
        for(int i =0 ;i < n ; i++ )
        {
            y ="";
            for(int j = 0; j < m; j++)
            {
                 y+=to_string(grid[i][j]);
                 y+=",";

            }
            row[y]++;
        }
        for(int j =0 ;j < m; j++ )
        {
            y ="";
            for(int i = 0; i < n; i++)
            {
                y+=to_string(grid[i][j]);
                  y+=",";

            }
            col[y]++;
        }
         int  o = 0 ;
        for(auto x: row)
        {
            if(col.count(x.first)!=0)
            {
                o+=(x.second * col[x.first]);
            }
            cout<<x.first<<endl;
        }
        cout<<endl;
        for(auto x : col)
        {
            cout<<x.first<<endl;
        }
        return o;
        
    }
};