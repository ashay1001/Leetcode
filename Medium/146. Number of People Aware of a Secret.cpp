class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<int> dp(n+1, 0);
        long mod = 1e9+7;
        long noOfPeopleSharingSecret = 0;
        int ans = 0;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++)
        {
            long noNewOfPeopleSharingSecret = dp[max(i-delay, 0)];
            long noPeopleForgetingSecret = dp[max(i-forget, 0)];
            
            noOfPeopleSharingSecret = (noOfPeopleSharingSecret + noNewOfPeopleSharingSecret - noPeopleForgetingSecret + mod) % mod;
            dp[i] = noOfPeopleSharingSecret;
        }
        for (int i = n - forget + 1; i <= n; i++) {
			ans = (ans + dp[i]) % mod;
		}
		return ans;
    }
};