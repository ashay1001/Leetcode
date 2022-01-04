class Solution {
public:
    int findComplement(int num) {
     
        int t = 1;
        while(num > t)
            t = t*2 + 1;
        return t-num;
        // or we we can write as return t^num
    }
};