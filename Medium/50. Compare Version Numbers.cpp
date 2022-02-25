class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        
        vector<string> v1, v2;
        split(version1, v1);
        split(version2, v2);
        
        int len = max(v1.size(), v2.size());
        
        for(int i=0; i<len; i++)
        {
            int first = i < v1.size() ? stoi(v1[i]) : 0;
            int second = i < v2.size() ? stoi(v2[i]) : 0;
            if(first < second)
                return -1;
            else if(first > second)
                return 1;
        }
        return 0;
    }
    
    void split(string s, vector<string> &v)
    {
        int start = 0;
        int end = s.find(".");
        while(end != -1)
        {
            v.push_back(s.substr(start, end - start));
            start = end + 1;
            end = s.find(".", start);
        }
        v.push_back(s.substr(start, end - start));
    }
};