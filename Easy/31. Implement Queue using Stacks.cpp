class MyQueue {
public:
    stack<int> input, output;

    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int t = peek();
        output.pop();
        return t;
    }
    
    int peek() {
        if(output.empty())
        {
            while (input.size())
            {
                output.push(input.top());
                input.pop();    
            }
        }
        return output.top();
    }
    
    bool empty() {
        
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */