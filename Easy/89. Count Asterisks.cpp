class Solution {
public:
    int countAsterisks(string s) {
        
        int count = 0;
        bool pipe = false;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '*' and pipe == false)
                count++;
            else if(s[i] == '|')
                pipe = !pipe;
        }
        return count;
    }
};