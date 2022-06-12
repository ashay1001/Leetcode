class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        return mergeSort(nums, 0, nums.size()-1);
    }
    
    int mergeSort(vector<int> &nums, int start, int end)
    {
        int count = 0;
        
        if(start < end)
        {
            int mid = (start + end)/2;
            count = mergeSort(nums, start, mid);
            count += mergeSort(nums, mid+1, end);
            
            for (int i = start, j = mid+1; i <= mid && j <= end;)
            {
			    if (nums[i] > (long) 2*nums[j])
                {
                    count += mid-i+1;
                    j++;
                }
                else 
                    i++;
		    }
            
            merge(nums, start, mid, end);
        }
        return count;
    }
    
    void merge(vector<int> &nums, int start, int mid, int end)
    {
        vector<int> temp(end-start+1);
        int count = 0, k = 0, i = start, j = mid+1;
        
        while(i<=mid and j<=end)
        {
            if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
            {
                temp[k++] = nums[j++];
            }
        }
        
        while(i <= mid)
            temp[k++] = nums[i++];
        while(j <= end)
            temp[k++] = nums[j++];
        
        for(int i=0; i<(end-start+1); i++)
            nums[i+start] = temp[i];
    }
};