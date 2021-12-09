//DFS approch
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

// BFS approch

/*

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
                
        int arraySize = arr.size();
        queue<int> q;
        
        q.push(start);
    
        while(!q.empty())
        {
            int currIndex=q.front();
            q.pop();
                
            if(arr[currIndex] == 0)
                return true;
            
            if(arr[currIndex] < 0) continue;
            
            if (currIndex + arr[currIndex] < arraySize)
                q.push(currIndex + arr[currIndex]);
            
            if (currIndex - arr[currIndex] >= 0)
                q.push(currIndex - arr[currIndex]);
            
            arr[currIndex] = -1;  
        }
        return false;
    }
};

*/