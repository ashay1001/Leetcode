class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
                               ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        int count = 0;
        for(auto s : words)
        {
            string temp = "";
            for(int i=0; i<s.size(); i++)
            {
                temp += code[s[i]-'a'];
            }
            if(st.find(temp) == st.end())
                count++;
            st.insert(temp);
        }
        return count;
    }
};