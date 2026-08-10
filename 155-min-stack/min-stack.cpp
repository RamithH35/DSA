class MinStack {
public:
    stack<long long> s;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int value) {
        long long val = value;

        if (s.empty()) {
            mini = val;
            s.push(val);
        }
        else if (val < mini) {
            s.push(2LL * val - mini);
            mini = val;
        }
        else {
            s.push(val);
        }
    }

    void pop() {
        if (s.empty()) return;

        long long x = s.top();
        s.pop();
        if (x < mini) {
            mini = 2LL * mini - x;
        }
    }

    int top() {
        if (s.empty()) return -1;

        long long x = s.top();

        if (x < mini) {
            return (int)mini;
        }

        return (int)x;
    }

    int getMin() {
        if (s.empty()) return -1;

        return (int)mini;
    }
};