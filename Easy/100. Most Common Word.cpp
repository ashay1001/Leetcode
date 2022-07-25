class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban (banned.begin(), banned.end());
        unordered_map<string, int> count;
        //cout<<paragraph<<endl;
        
        for (auto &c: paragraph) 
            c = isalpha(c) ? tolower(c) : ' ';
        //cout<<paragraph<<endl;
        istringstream iss(paragraph);
        string w;
        pair<string, int> res ("", 0);
        
        while (iss >> w)
        {
            if (ban.find(w) == ban.end())
            {
                count[w]++;
                if(count[w] > res.second)
                    res = make_pair(w, count[w]);
            }
            //cout<<w<<" ";
        }
        return res.first;
    }
};