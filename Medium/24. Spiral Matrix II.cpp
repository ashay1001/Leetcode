class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
     
        vector<vector<int>> result(n, vector<int> (n));
        int top, bottom, left, right, dir, count;
        dir = 0;
        top = 0;
        bottom = n-1;
        left = 0;
        right = n-1;
        count = 1;
        while(top <= bottom && left <= right)
        {
            if(dir == 0)
            {
                for(int i=left; i<=right; i++)
                {
                    result[top][i] = count++;
                }
                top++;
            }
            else if(dir == 1)
            {
                for(int i=top; i<=bottom; i++)
                {
                    result[i][right] = count++;
                }
                right--;
            }
            else if(dir == 2)
            {
                for(int i=right; i>=left; i--)
                {
                    result[bottom][i] = count++;
                }
                bottom--;
            }
            else if(dir == 3)
            {
                for(int i=bottom; i>=top; i--)
                {
                    result[i][left] = count++;
                }
                left++;
            }
            
            dir = (dir+1) % 4;
        }
        return result;
    }
};