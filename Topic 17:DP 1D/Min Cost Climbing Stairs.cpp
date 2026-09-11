class Solution {
public:
    int dp(vector<int>& cost ,vector<int>&dpp , int i)
    {
        if(i >= cost.size())
        {
            return 0;
        }
        if(dpp[i]!=-1)
        {
            return dpp[i];
        }
        int one = cost[i] + dp(cost , dpp , i+1);
        int two = cost[i] + dp(cost , dpp , i+2);
        return dpp[i] = min(one , two); 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dpp(cost.size()+1 ,-1),dppp(cost.size()+1 ,-1);
        return min(dp(cost , dpp , 0 ) ,dp(cost , dppp , 1) );
        
    }
};