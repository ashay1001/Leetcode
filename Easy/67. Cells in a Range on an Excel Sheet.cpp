class Solution {
public:
    vector<string> cellsInRange(string s) {
     
        char low = s[1];
        char high = s[4];
        char l = s[0];
        char r = s[3];
        
        vector<string> ans;
        while(l <= r)
        {
            for(char i=low; i<=high; i++)
            {
                string t = "";
                t += l;
                t += i;
                ans.push_back(t);
            }
            l += 1;
        }
        return ans;
    }
};