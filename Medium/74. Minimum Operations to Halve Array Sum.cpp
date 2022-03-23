class Solution {
public:
    int halveArray(vector<int>& nums) {
     
        priority_queue<double> pq;
        double sum = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            pq.push(nums[i]);
        }
        sum = sum / 2;
        
        while(sum > 0)
        {
            double temp = pq.top()/2;
            sum = sum - temp;
            pq.pop();
            pq.push(temp);
            count++;
        }
        return count;
    }
};