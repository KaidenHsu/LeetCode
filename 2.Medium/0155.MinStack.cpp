// 7/22/22
class MinStack {
private:
    class Data {
    public:
        Data(int v, int m) : val(v), min(m) {}
        int val;
        int min;
    };
    
    stack<Data> s;
    
public:
    void push(int x) { s.push(Data(x, s.empty() ? x : min(x, s.top().min))); }
    void pop() { s.pop(); }
    int top() { return s.top().val; }
    int getMin() { return s.top().min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */