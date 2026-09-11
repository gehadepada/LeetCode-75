class Solution {
public:
    int tryy(int m , int n , int i , int j , vector<vector<int>>&dp)
    {
        if( i >= n || j >= m )
        {
            return 0;
        }
        if( i == n-1 &&  j == m-1)
        {
            return 1;

        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int right = tryy(m , n , i , j+1,dp);
        int down =tryy(m ,n , i+1 , j ,dp);
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1 , vector<int>(n+1 ,-1));
        return tryy(n , m , 0 , 0 , dp );
        
    }
};