/**
 * Key Learning Point: Amortized O(1) runtime -> n operations takes overall O(n) time. Consider
 * sequence of push and pops. Each of the pushes is O(1), the first pop is O(n), shifting stuff to
 * the second stack and subsequent pops are O(1). Thus overall is O(n) for these n operations and
 * amortized = O(n) / n = O(1)
 *
 * Runtime: O(n) (the worst is the first pop) / Amortized O(1)
 *
 * Memory: O(n)? Scales proportionally with the number of elements?
 */
class MyQueue {
public:
    stack<int> first{};
    stack<int> second{};
    int to_peek;
    MyQueue() {
        
    }
    
    void push(int x) {
        if (first.empty())
        {
            to_peek = x;
        }
        first.push(x);
    }
    
    int pop() {
        if (second.empty())
        {
            while (!first.empty())
            {
                second.push(first.top());
                first.pop();
            }
        }

        int to_return = second.top();
        second.pop();
        return to_return;
    }
    
    int peek() {
        if (!second.empty())
        {
            return second.top();
        }

        return to_peek;
    }
    
    bool empty() {
        return first.empty() && second.empty();
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
