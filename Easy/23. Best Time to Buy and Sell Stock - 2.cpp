class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0, min = prices[0], currProfit = 0;
        
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i]<min)
            {
                min = prices[i];
            }
            else
            {
                currProfit = prices[i]-min;
                profit = max(profit, currProfit);
            }
        }
        return profit;
    }
};