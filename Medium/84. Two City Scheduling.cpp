class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
     
        int minCost = 0;
        vector<int> refund;
        for(auto c : costs)
        {
            minCost += c[0];
            refund.push_back(c[1]-c[0]);
        }
        sort(refund.begin(), refund.end());
        
        for(int i=0; i<costs.size()/2; i++)
        {
            minCost += refund[i];
        }
        return minCost;
    }
};