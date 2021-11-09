class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
     
        unordered_map<int , vector<int>> mp;
        
        for(int i=0; i<26; i++)
        {
            vector<int> v{};
            mp[i] = v;
        }
        
        for(auto &word : words)
        {
            int mask = 0;
            
            for(auto ch: word)
            {
                mask = mask | (1 << (ch - 'a'));
            }
            
            for (int i = 0; i < 26; i++) {
                if ((mask & (1 << i)) != 0) {
                    mp[i].push_back(mask);
                }
            }
        }
        
        vector<int> res;
        for(auto &puzzle : puzzles)
        {
            int puzzle_mask = 0;
            for(auto ch: puzzle)
            {
                puzzle_mask = puzzle_mask | (1 << (ch - 'a'));
            }
            
            int firstChar = puzzle[0] - 'a';
            int count = 0;
            
            for(auto word_mask : mp[firstChar])
            {
                if((word_mask & puzzle_mask) == word_mask)
                    count++;
            }
            res.push_back(count);
        }
        return res;
    }
};