class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result = {intervals[0]};
        
        for(int i=1; i<intervals.size(); i++)
        {
            int row = result.size()-1;
            if(result[row][1] >= intervals[i][1])
            {
                continue;
            }
            else if(result[row][1] >= intervals[i][0])
            {
                vector<int> t = {result[row][0], intervals[i][1]};
                result.pop_back();
                result.push_back(t);
            }
            else
            {
                vector<int> t = {intervals[i][0], intervals[i][1]};
                result.push_back(t);
            }
        }
        return result;
    }
};