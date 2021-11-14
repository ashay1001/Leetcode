class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tempreture) {
        vector<int> ans(tempreture.size());
        stack<int> s;
        s.push(0);
        for(int i=1; i<tempreture.size(); i++)
        {
            while(s.empty()==false and tempreture[s.top()] < tempreture[i])
            {
                ans[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};