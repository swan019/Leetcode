class MyQueue {
    void insert_At_end(int k, stack<int>& st2){
        if(st2.empty()){
            st2.push(k);
            return;
        }

        int temp = st2.top();
        st2.pop();
        insert_At_end(k, st2);
        st2.push(temp);
        return;
    }
public:
    stack<int> st1, st2;

    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
        insert_At_end(st1.top(), st2);
    }
    
    int pop() {
        if(!st2.empty()){
            int k = st2.top();
            st2.pop();
            return k;
        }
        return -1;
    }
    
    int peek() {
        if(!st2.empty()){
            return st2.top();
        }
        return -1;
    }
    
    bool empty() {
        return st2.empty();
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