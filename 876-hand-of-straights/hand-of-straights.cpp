class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int group) {
        if(hand.size()%group!=0)
            return false;
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>mp;
        for(auto &x:hand)
        {
            mp[x]++;
        }
        for(auto &x:mp)
            pq.push(x.first);
        while(!pq.empty())
        {
            while(!pq.empty()&&mp[pq.top()]==0)
                pq.pop();
            if(pq.empty())
                break;
            int x=pq.top();
            for(int i=0;i<group;i++)
            {
                if(mp.find(x+i)==mp.end() || mp[x+i]==0)
                    return false;
                mp[x+i]--;
            }
        }
        return true;
    }
};