class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        vector<int> last(26,0);
        
        for(int i=0;i<S.size();i++) 
            last[S[i]-'a']=i;
        
        vector<int> res;
        int partition_end = 0, current_start = 0;
        
        for(int i=0;i<S.size();i++) 
        {
            partition_end = max(partition_end, last[S[i]-'a']);
            
            if(i == partition_end) 
            {
                res.push_back(i-current_start+1);
                current_start=i+1;
            }
        }
        return res;
    }
};