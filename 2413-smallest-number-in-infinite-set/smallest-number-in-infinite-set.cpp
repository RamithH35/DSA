class SmallestInfiniteSet {
public:
    int current;
    priority_queue<int,vector<int>,greater<int>>pq;
    set<int>st;
    SmallestInfiniteSet() {
        current=1;
    }
    
    int popSmallest() {
        if(!pq.empty())
        {
            if(pq.top()<current)
            {
                int x=pq.top();
                pq.pop();
                st.erase(x);
                return x;
            }
        }
        int y=current;
        current++;
        return y;
    }
    
    void addBack(int num) {
        if(st.count(num))
            return;
        else if(num <current)
        {
            pq.push(num);
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */