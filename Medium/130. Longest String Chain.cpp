class Solution {
public:
    
    static bool compare(const string &s1, const string &s2)
    {
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
     
        unordered_map<string, int> mp;
        int count = 1;
        
        sort(words.begin(), words.end(), compare);
        for(string word : words)
        {
            mp[word] = 1;
            for(int i=0; i<word.size(); i++)
            {
                //cout<<"word.substr(0, i) = "<<word.substr(0, i)<<" word.substr(i+1) = "<<word.substr(i+1)<<endl;
                string prev = word.substr(0, i) + word.substr(i+1);
                if(mp.find(prev) != mp.end())
                {
                    mp[word] = mp[prev] + 1;
                    count = max(count, mp[word]);
                }
            }
            //cout<<"------------------------------"<<endl;
        }
        return count;
    }
};