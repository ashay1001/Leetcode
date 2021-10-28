class Solution {
public:
    
    int binarySearch(vector<int> &arr, int low, int high, int key)
    {
        /*
        approch used here is to divide the array into two halves. As the sorted array is rotated there are two
        posibilities, either left sub array will be sorted or right array will be sorted.
        */
        
        if(low > high) {return -1;}
        
        int mid = (low + high)/2;
        if(arr[mid] == key) {return mid;}
        
        /* If left sub array is sorted */
        if(arr[low] <= arr[mid])
        {
            if(key <= arr[mid] && key >= arr[low]) 
                return binarySearch(arr, low, mid-1, key);
            
            /* If key not lies in first half subarray, search within other half */
            return binarySearch(arr, mid+1, high, key);
        }
        
         /* If first subarray is not sorted, then other half must be sorted */
        if (key >= arr[mid] && key <= arr[high])
            return binarySearch(arr, mid + 1, high, key);
        
        /* if none of the above is true it means 1st half is not sorted and key if present, will be in the 1st half */
        
        return binarySearch(arr, low, mid-1, key);
            
    }
    
    int search(vector<int>& nums, int target) {
        
        return binarySearch(nums, 0, nums.size()-1, target);
        
    }
};