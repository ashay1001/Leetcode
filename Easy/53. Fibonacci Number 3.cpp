class Solution {
public:
    int fib(int N) 
    {
        if(N < 2) 
            return N;
    	
        int a = 0, b = 1, c = a + b;
        
        for(int i = 2; i < N; i++)
        {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};