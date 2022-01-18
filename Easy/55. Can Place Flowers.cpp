class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int count = 0;
        
        if(flowerbed.size() == 1)
        {
            if(flowerbed[0] == 0 && (n==0 || n==1))
                return true;
            else if(flowerbed[0] == 1 && n==0)
                return true;
            else
                return false;
        }
        
        if(flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            flowerbed[0] = 1;
            count++;
        }
        
        for(int i=1; i<flowerbed.size()-1; i++)
        {
            if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
            {
                count++;
                flowerbed[i] = 1;
            }
        }
        
        if(flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] ==0)
            count++;
        
        if(count >= n)
            return true;
        else
            return false;
    }
};