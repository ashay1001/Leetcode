/* if we XOR all numbers except the unique number then all remaining numbers when XOR together,
will produce output as zero and when again XOR'ed with unique number, will produce output as same number.*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int t = 0;
        for(int i: nums)
        {
            t ^= i;
        }
        
        return t;
    }
};