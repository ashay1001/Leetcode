class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
     
        if(coordinates.size() <= 2) return true;
        sort(coordinates.begin(), coordinates.end());
        double slope;
        if(coordinates[1][0] == 0 and coordinates[0][0] == 0)
        {
            slope = 0;
        }
        else
        {
            slope = (double)abs(coordinates[1][1]-coordinates[0][1]) / abs(coordinates[1][0]-coordinates[0][0]);
        }
        for(int i=2; i<coordinates.size(); i++)
        {
            double x2 = coordinates[i][0];
            double x1 = coordinates[i-1][0];
            double new_slope;
            if(x2 == 0 and x1 == 0)
                new_slope = 0;
            else
                new_slope = abs(coordinates[i][1]-coordinates[i-1][1]) / abs(x2-x1);
            if(slope != new_slope)
                return false;
            slope = new_slope;
        }
        return true;
    }
};