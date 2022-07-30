class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for(int i=0; i<32; i++)
        {
            uint32_t bit = (n >> i) & 1;    //taking LSB from n
            result = result | (bit << (31-i)); //and putting that bit at MSB of result
        }
        return result;
    }
};