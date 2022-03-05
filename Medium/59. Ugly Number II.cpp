class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> ans(1,1);
        int t2 = 0, t3 = 0, t5 = 0;
        while(ans.size() < n)
        {
            ans.push_back(min(ans[t2] * 2, min(ans[t3] * 3, ans[t5] * 5)));
            
            if(ans.back() == ans[t2] * 2) t2++;
            if(ans.back() == ans[t3] * 3) t3++;
            if(ans.back() == ans[t5] * 5) t5++;
        }
        return ans.back();
    }
};