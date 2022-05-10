class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.length() == 0) return {};
        
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans = {""};
        
        for(auto i : digits)
        {
            vector<string> temp;
            for(auto combination : map[i-'0'])
            {
                for(auto str : ans)
                {
                    temp.push_back(str + combination);
                }
            }
            ans = temp;
        }
        return ans;
    }
};