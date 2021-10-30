class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0, min = prices[0];
        vector<int> arr(prices.size());
        arr[0] = 0;
        
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i]<min)
            {
                min = prices[i];
                arr[i] = 0;
            }
            else
            {
                arr[i] = prices[i]-min;
                profit = max(profit, arr[i]);
            }
        }
        return profit;
    }
};