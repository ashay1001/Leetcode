class Solution {
public:
   bool hasAllCodes(string s, int k) {
	
        //Edge case
        if(k > s.size()) return false;
        
        unordered_set<string> result;
        
        //Insertion into the set
        for(int i =0;i<= s.size()-k;i++)
            result.insert(s.substr(i,k));
        
        //Comparing res with 2^k
        return result.size() == pow(2,k);
    }
};