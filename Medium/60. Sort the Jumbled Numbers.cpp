class Solution {
public:
    bool static compare( const vector<int>& v1, const vector<int>& v2 ) 
    {
            return v1[0] < v2[0];
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++)
        {
            vector<int> v;
            v.push_back(convert(nums[i], mapping));
            v.push_back(nums[i]);
            ans.push_back(v);
        }
        //display(ans);
        sort(ans.begin(), ans.end(), compare);
        //display(ans);
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] = ans[i][1];
        }
        return nums;
    }
    
    int convert(int n, vector<int>& mp)
    {
        if(n == 0) return mp[0];
        int sum = 0;
        int mul = 1;
        
        while(n>0)
        {
            sum += (mp[n%10]) * mul;
            mul *= 10;
            n /= 10;
        }
        return sum;
    }
    
    void display(vector<vector<int>> &v)
    {
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[0].size(); j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
};