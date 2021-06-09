//Sieve of Eratosthenes

class Solution {

public:

   int countPrimes(int n) 
   {

      if (n <= 2) 
      {
         return 0;
      }

      vector<bool> primes(n, true);               // assuming all are prime unless otherwise
      int topBound = sqrt(n);
      int numPrimes = n - 2;                      // excluding 0 and 1

      for (int i = 2; i <= topBound; i++) 
      {
         for (int j = i * i; j < n; j += i) 
         {
            if (primes[j]) 
            {
               primes[j] = false;
               numPrimes--;
            }
         }
      }
      return numPrimes;
   }

};
