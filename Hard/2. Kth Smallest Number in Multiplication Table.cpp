class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        
        int low = 1, high = m * n;
        while (low < high) 
        {
            int mid = (low + high)/2;
            
            //if enough() returns true it means there enough elements which are less than mid 
            //and their count is greater than or equal to k.
            if (enough(mid, m, n, k))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
    
    //This function checks if there are enough element which are less than mid 
    //and if their count is greater than k or not
    bool enough(int mid, int row, int column, int k)
    {
        int count = 0;
        for (int i = 1; i <= row; i++) {
            count += min(mid / i, column);
        }
        return count >= k;
    }
};