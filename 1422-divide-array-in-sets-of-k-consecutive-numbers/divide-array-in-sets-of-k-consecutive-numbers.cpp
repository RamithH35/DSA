class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)
            return false;
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>mp;
        for(auto&x:nums)
            mp[x]++;
        for(auto&y:mp)
            pq.push(y.first);
        while(!pq.empty())
        {
            while (!pq.empty() && mp.find(pq.top()) == mp.end())
                pq.pop();
            if (pq.empty())
                break;
            int x=pq.top();
            for(int i=0;i<k;i++)
            {
                if(mp.find(x+i)==mp.end())
                    return false;
                mp[x+i]--;
                if(mp[x+i]==0)
                    mp.erase(x+i);
                
            }
            
        }
        return true;
    }
};