class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
     
        if(arr[start] == 0) return true;
        
        int left = start - arr[start];
        int right = start + arr[start];
        arr[start] = -1;
        bool lcheck = false, rcheck = false;
        
        if(left >= 0 && arr[left] != -1)
            lcheck = canReach(arr, left);
        if(right < arr.size() && arr[right] != -1)
            rcheck = canReach(arr, right);
        
        return (lcheck || rcheck);
    }
};