class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> digit_sum;
        int result = -1;
        vector<pair<int,int>> ans;
        
        for( int i=0;i<n ;i++)
        { 
            int a=0, sum=0;
            a=nums[i]; 
             while (a != 0) 
             {
                sum = sum + a % 10;
                 a = a / 10;
            }
            digit_sum.push_back(sum);
        }
        
        for(int i=0 ;i<n;i++){
            ans.push_back({digit_sum[i], nums[i]});
        }
        
        sort(ans.begin(), ans.end());
      
         for(int i=1;i<n ;i++)
         {
             if(ans[i].first == ans[i-1].first)
                 result = max(result, ans[i].second + ans[i-1].second);
         }
        return result;
    }
};