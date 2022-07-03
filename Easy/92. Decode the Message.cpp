class Solution {
public:
    string decodeMessage(string key, string message) {
        
        unordered_map<char, char> mp;
        int counter = 0;
        string str = "";
        for(int i=0; i<key.size(); i++)
        {
            if(key[i] != ' ' and mp.find(key[i]) ==mp.end())
            {
                mp[key[i]] = 'a'+ counter;
                counter++;
            }
        }
        for(int i=0; i<message.size(); i++)
        {
            if(message[i] == ' ')
                str += ' ';
            else
                str += mp[message[i]];
        }
        return str;
    }
};