class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size()-1; i++) {
            if (prices[i] < prices[i + 1])
                profit = profit + (prices[i+1] - prices[i]);
        }
        return profit;
    }
};

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/1569298/Very-Easy-to-understand-or-C++-or-With-Explanation-and-examples-or-With-proof
*/