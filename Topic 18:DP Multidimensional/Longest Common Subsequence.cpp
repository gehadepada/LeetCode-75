class Solution {
public:
    int tryy(int i , int j , int n , int m , string&t , string&tt , vector<vector<int>>&dp)
    {
        if(i>= n || j >= m )
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int take = 0 , notTake =0 , notTake2=0;
        if(t[i] == tt[j])
        {
            take = 1 + tryy(i+1 , j +1 , n , m , t,tt,dp);
        }
        else{
        notTake = tryy(i+1 , j , n , m , t,tt,dp);
        notTake2 = tryy(i , j+1 , n , m , t,tt,dp);
        }
        return dp[i][j] = max({take ,notTake ,notTake2});


    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1 ,-1));
        return tryy(0 , 0 , n , m ,text1 , text2, dp);
        
    }
};