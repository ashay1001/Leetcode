class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int sum = 0, ans, left = 0, right = cardPoints.size()-k;
        
        for(int i=0; i<cardPoints.size(); i++)
            sum += cardPoints[i];
        for(int i=0; i<cardPoints.size()-k; i++)
            sum -= cardPoints[i];
        ans = sum;
        
        while(right < cardPoints.size())
        {
            sum = sum + cardPoints[left++] - cardPoints[right++];
            ans = max(ans, sum);
        }
        return ans;        
    }
};