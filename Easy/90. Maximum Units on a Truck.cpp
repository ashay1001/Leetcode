class Solution {
public:
    
    bool static compare(vector<int> &v1, vector<int> &v2)
    {
        return v1[1] > v2[1]; 
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int units = 0, available_size;
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        for(int i=0; i<boxTypes.size(); i++)
        {
            available_size = min(truckSize, boxTypes[i][0]);
            truckSize -= available_size;
            units += available_size * boxTypes[i][1];
            
            if(truckSize == 0)
                break;
        }
        
        return units;
    }
};