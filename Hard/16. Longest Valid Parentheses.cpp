class Solution {
public:
    int longestValidParentheses(string s) {
     
        stack<int> st;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            
            else if(!st.empty() and s[st.top()] == '(')
                st.pop();
            else
                st.push(i);
        }
        
        int end = s.length();
        int res = 0;
        if(st.empty()) return end;
        
        while(!st.empty())
        {
            int start = st.top();
            st.pop();
            res = max(res, end-start-1);
            end = start;
        }
        return max(res, end);       // This is required to hanndle test cases where string from 0th index to 1st imbalance is valid Ex: "())"
    }
};