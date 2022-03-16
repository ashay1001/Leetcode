class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int index = 0;
        
        for(int i=0; i<popped.size(); i++)
        {
            if(!st.empty() && popped[i]==st.top())
                st.pop();
                
            else
            {
                while(index < pushed.size() && popped[i] != pushed[index])
                {
                    st.push(pushed[index]);
                    index++;
                }
                index++;
            }
        }
        return st.empty();
    }
};