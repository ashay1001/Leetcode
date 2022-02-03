class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     
        if(nums.size() < 4) return {};
        
        vector<vector<int>> result;   
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
     
        for(int i=0; i<nums.size()-1; i++)
        {
            for(int j=i+1; j<nums.size();j++)
            {
                int sum = target - nums[i] - nums[j];
                int left = j+1, right = nums.size()-1;
                
                while(left < right)
                {
                    if(nums[left]+nums[right] == sum)
                    {
                        s.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++; right--;
                    }
                    else if(nums[left]+nums[right] < sum)
                        left++;
                    else
                        right--;
                }
            }
        }
        result.assign(s.begin(), s.end());
        return result;
    }
};