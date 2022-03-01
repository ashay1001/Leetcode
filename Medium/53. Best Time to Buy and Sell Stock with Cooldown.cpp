class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() <= 1) return 0;
        
        int dp[prices.size()][2];
        memset(dp, -1, sizeof(dp));
        
        return dfs(prices, dp, 0, 1);
    }
    // 'state' represents previous state also, state == 1 --> buying, state == 0 ---> cooldown
    int dfs(vector<int> &prices, int dp[][2], int i, int state)
    {
        if(i >= prices.size()) return 0;
        
        if(dp[i][state] != -1) return dp[i][state];
        
        if(state == 1)
        {
            int buyingProfit = dfs(prices, dp, i+1, 0) - prices[i];
            int cooldown = dfs(prices, dp, i+1, state);
            dp[i][state] = max(buyingProfit, cooldown);
        }
        else
        {
            int sellProfit = dfs(prices, dp, i+2, 1) + prices[i];
            int cooldown = dfs(prices, dp, i+1, state);
            dp[i][state] = max(sellProfit, cooldown);
        }
        
        return dp[i][state];
    }
};