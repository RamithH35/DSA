class MKAverage {
public:
    queue<int>q;
    multiset<int>low;
    multiset<int>mid;
    multiset<int>high;
    multiset<int>temp;
    bool flag;
    int m;
    int k;
    long long midsum;
    MKAverage(int m, int k) {
        this->m=m;
        this->k=k;
        midsum=0;
        flag=false;
    }
    void rebalance()
    {
        while(low.size()>k)
        {
            auto it = prev(low.end());
            int x=*it;
            low.erase(it);
            mid.insert(x);
            midsum+=x;
        }
        while(low.size()<k)
        {
            auto it=mid.begin();
            int x=*it;
            mid.erase(it);
            midsum-=x;
            low.insert(x);
        }
        while(high.size()>k)
        {
            auto it=high.begin();
            int x=*it;
            high.erase(it);
            mid.insert(x);
            midsum+=x;
        }
        while(high.size()<k)
        {
            auto it=prev(mid.end());
            int x=*it;
            mid.erase(it);
            high.insert(x);
            midsum-=x;
        }
    }
    
    void addElement(int num) {
        if(q.size()<m)
        {
            q.push(num);
            temp.insert(num);
            if(q.size()==m && !flag)
            {
                while(low.size()<k)
                {
                    auto it=temp.begin();
                    low.insert(*it);
                    temp.erase(it);
                }
                while(mid.size()<m-2*k)
                {
                    auto it = temp.begin();
                    mid.insert(*it);
                    midsum+=*it;
                    temp.erase(it);
                }
                while(!temp.empty())
                {
                    auto it=prev(temp.end());
                    high.insert(*it);
                    temp.erase(it);
                }
                flag=true;
            }
        }
        else
        {
            q.push(num);
            int x=q.front();
            q.pop();
            auto it = low.find(x);
            if(it !=low.end())
                low.erase(it);
            else
            {
                it=mid.find(x);
                if(it!=mid.end())
                {
                    midsum-=x;
                    mid.erase(it);
                }
                else
                {
                    it=high.find(x);
                    high.erase(it);
                }
            }
            if (!low.empty() && num <= *low.rbegin())
                low.insert(num);
            else if (!high.empty() && num >= *high.begin())
                high.insert(num);
            else
            {
                mid.insert(num);
                midsum += num;
            }
            rebalance();
        }
    }
    
    int calculateMKAverage() {
        if(q.size()<m)
            return -1;
        return midsum/(m-2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */