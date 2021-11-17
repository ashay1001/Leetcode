class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n+m-2; // total steps = n-1 + m-1
        int r = min(n,m) - 1; // will iterate on the minimum for efficiency = (total) C (min(right, down))
        
        double res = 1;
        
		// compute nCr
        for(int i=1; i<=r; i++){
            
            res = res * (N) / i;
            N--;
        }
        
        return (int)res;
    }
};


/*
Observation: If you observe it care fully, our robot has to move n-1 steps right and m-1 steps down in any order 
to reach the right bottom of the grid. You will understand this more with the following example.

Example: We had 3x7 grid, robot needs to take (3-1) = 2 steps down overall and 7-1 = 6 steps right overall to 
reach the bottom right of the grid. This is a total of 8 steps. And the ordering doesn't matter 
like: D D R R R R R R or D R D R R R R R or R R R R R R D D will all do the job, and all of this is 
noting but the permutation of total steps. So this is nothing but number of ways of choose D in the 
8 blanks or number of ways of choosing R in the 8 blanks which is nothing but 8C6 or 8C2 = 28 
(both will do the job)
*/
