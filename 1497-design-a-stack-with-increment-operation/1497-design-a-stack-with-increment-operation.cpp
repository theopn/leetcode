class CustomStack {
public:
    vector<int> stack;
    int size;
    int maxSize;

    CustomStack(int maxSize) {
        stack.resize(maxSize);
        size = 0;
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (size + 1 > maxSize) return;

        stack[size] = x;
        size++;
    }
    
    int pop() {
        if (size == 0) return -1;

        int tmp = stack[size - 1];
        stack[size - 1] = NULL;
        size--;
        return tmp;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k && i < size; i++) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */