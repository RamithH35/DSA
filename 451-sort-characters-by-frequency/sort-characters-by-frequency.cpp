class Solution {
public:
    struct cmp{
        bool operator()(const pair<char,int>&a,const pair<char,int>&b)
        {
            if(a.second!=b.second)
                return b.second>a.second;
            return b.first>a.first;
        }
    };
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp>pq;
        for(char c:s)
            freq[c]++;
        for(auto &x:freq)
            pq.push({x.first,x.second});
        string ans="";
        while(pq.size())
        {
            auto c=pq.top();
            pq.pop();
            string temp=string(c.second,c.first);
            ans+=temp;
        }
        return ans;
    }
};