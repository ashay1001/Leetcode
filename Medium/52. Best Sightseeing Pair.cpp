class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
     
        int maxVal = values[0] + 0;
        int ans = INT_MIN;
        
        for(int i=1; i<values.size(); i++)
        {
            ans = max(ans, maxVal + values[i] - i);
            maxVal = max(maxVal, values[i] + i);
        }
        return ans;
    }
};