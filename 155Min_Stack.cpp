class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        
        int minV = x;
        if(!data.empty()){            
            minV = min(mins[data.size()-1], minV);
        }
        data.push_back(x);
        mins.push_back(minV);
    }
    
    void pop() {
        data.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return mins.back();
    }
    
    vector<int> data;
    vector<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */