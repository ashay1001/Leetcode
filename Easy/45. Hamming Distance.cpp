class Solution {
public:
    int hammingDistance(int x, int y) {
     
        int result = x^y, count = 0;
        while(result)
        {
            if(result & 1)
                count++;
            result = result>>1;
        }
        return count;
    }
};