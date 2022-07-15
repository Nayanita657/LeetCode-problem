https://leetcode.com/problems/min-stack/

*************************************SOLUTION*********************************

class MinStack {
public:
    
    stack<pair<long long, long long>> st;
    int global_min;
    
    MinStack() 
    {
        global_min = INT_MAX;
    }
    
    void push(int val) 
    {
        if(global_min > val)
            global_min = val;
        st.push({val,global_min});
    }
    
    void pop() 
    {
        st.pop();
        if(st.empty())
            global_min = INT_MAX;
        else
            global_min = st.top().second;
    }
    
    int top() 
    {
        return st.top().first;
    }
    
    int getMin() 
    {
        return global_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
