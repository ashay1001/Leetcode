class Solution {
public:
    int bitwiseComplement(int n) {
        
        int t = 1;
        while(n > t)
            t = t*2 + 1;
        return t-n;
        // or we we can write as return t^n
    }
};