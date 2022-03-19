class FreqStack {
public:
    int maxfreq;
    unordered_map<int, int> mp;
    unordered_map<int, stack<int>> freq_stack;
    
    FreqStack() {
        maxfreq = 0;    
    }
    
    void push(int val) 
    {
        mp[val]++;
        
        if(mp[val] > maxfreq)
            maxfreq = mp[val];
        
        freq_stack[mp[val]].push(val);
    }
    
    int pop() 
    {
        int top = freq_stack[maxfreq].top();
        freq_stack[maxfreq].pop();
        mp[top]--;
        
        if(freq_stack[maxfreq].empty())
        {
            freq_stack.erase(maxfreq);
            maxfreq--;
        }
        return top;
    }
};