#include <stack>

class Solution {
public:
    bool isValid(string s) {
     
        stack<char> st;
        
        for(int i=0; i<s.length(); i++)
        {
            switch(s[i])
            {
                case '(':
                case '[':
                case '{': st.push(s[i]); break;
                case ')': if(st.empty() || st.top()!='(') {return false;} else{st.pop(); break;}
                case ']': if(st.empty() || st.top()!='[') {return false;} else{st.pop(); break;}
                case '}': if(st.empty() || st.top()!='{') {return false;} else{st.pop(); break;}
                default: ;
            }
        }
        return st.empty();
    }
};