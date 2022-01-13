class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        
        sort(points.begin(), points.end(), [] (auto &p1, auto&p2) {
            return p1[1] < p2[1];
        });
        
        int count = 1;
        int arrowPos = points[0][1];
        
        for(int i=1; i<points.size(); i++)
        {
            if(points[i][0] > arrowPos)
            {
                count++;
                arrowPos = points[i][1];
            }
        }
        return count;
    }
};