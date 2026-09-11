class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& prices, int fee, int i, int hold) {
        if (i == prices.size())
            return 0;

        if (dp[i][hold] != -1)
            return dp[i][hold];

        if (hold == 0) {
            int skip = solve(prices, fee, i + 1, 0);
            int buy  = -prices[i] + solve(prices, fee, i + 1, 1);

            return dp[i][hold] = max(skip, buy);
        } else {
            int keep = solve(prices, fee, i + 1, 1);
            int sell = prices[i] - fee + solve(prices, fee, i + 1, 0);

            return dp[i][hold] = max(keep, sell);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));

        return solve(prices, fee, 0, 0);
    }
};