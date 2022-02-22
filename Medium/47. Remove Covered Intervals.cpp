class Solution {
public:
    
    bool static compare( const vector<int>& v1, const vector<int>& v2 ) 
    {
        if(v1[0]==v2[0])
            return v1[1]>v2[1];
        else
            return v1[0] < v2[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        
        sort(intervals.begin(), intervals.end(), compare);
        int count = 0, start = 0;
        
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[start][1] >= intervals[i][1])
                count++;
            else
                start = i;
        }
        return intervals.size()-count;
    }
};