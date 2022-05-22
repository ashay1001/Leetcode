class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        vector<int> temp(capacity.size());
        int count = 0;
        for(int i=0; i<capacity.size(); i++)
        {
            temp[i] = capacity[i]-rocks[i];
            if(temp[i] == 0)
                count++;
        }
        
        sort(temp.begin(), temp.end());
        
        for(int i=0; i<temp.size(); i++)
        {
            if(temp[i] != 0 and temp[i] <= additionalRocks)
            {
                additionalRocks -= temp[i];
                count++;
            }
        }
        return count;
    }
};