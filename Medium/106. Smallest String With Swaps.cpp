class UnionFind{
    private:
    vector<int> parent;
    
    public: 
    UnionFind(int n)
    {
        // cout<<n<<endl;
        parent=vector<int>(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        
    }
    
    void unify(int i,int j)
    {
        int abosoluteparenti = getParent(i);
        int absoluteparentj = getParent(j);
        
        if(abosoluteparenti != absoluteparentj)
        {
            parent[abosoluteparenti]=absoluteparentj;
        }
    }
    
    int getParent(int i)
    {
        // cout<<i<<endl;
        if(parent[i]==i)
            return i;
        parent[i]=getParent(parent[i]);
        return parent[i];
    }
    
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        UnionFind uf(s.size());
        
        for(auto& p: pairs)
        {
            uf.unify(p[0], p[1]);
        }
        
        unordered_map<int, priority_queue<char,vector<char>,greater<char>>> map;
        
        for(int i=0; i<s.size(); i++)
        {
            int component = uf.getParent(i);
            map[component].push(s[i]);
        }
        
        string ans;
        for(int i=0; i<s.size(); i++)
        {
            ans.push_back(map[uf.getParent(i)].top());
            map[uf.getParent(i)].pop();
        }
        
        return ans;
    }
};