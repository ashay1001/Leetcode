class CombinationIterator {
public:
    vector<string> ans;
    int ptr = 0;
    CombinationIterator(string characters, int combinationLength) {
        
        generateCombination(characters, characters.length(), 0, combinationLength, "");
        ptr = 0;
    }
    
    string next() {
        return ans[ptr++];
    }
    
    bool hasNext() {
        return ptr<ans.size()?true:false;
    }
    
    // this method will generate all the possible combination of given length
    //by either including the character or excluding it. whenever the length of newly 
    //formed combination exceeds the given length we will simply return.
    
    void generateCombination(string s, int s_len, int pos, int len ,string result)
    {
        if(len == 0)
        {
            ans.push_back(result);
            return;
        }
        if(pos >= s_len) {return;}
        
        result += s[pos];
        generateCombination(s, s_len, pos+1, len-1, result);
        result.pop_back();
        generateCombination(s, s_len, pos+1, len, result);
        
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */