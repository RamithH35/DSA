class Solution {
public:
    struct Info{
        int freq;
        int first;
        int last;
    };
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,Info>mp;
        int degree=0;
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            if(mp.find(x)==mp.end())
            {
                mp[x].freq=1;
                mp[x].first=i;
                mp[x].last=i;

            }
            else
            {
                mp[x].freq++;
                mp[x].last=i;
            }
            degree=max(degree,mp[x].freq);
        }
        for(auto &y:mp)
        {
            if(y.second.freq==degree)
                res=min(res,(y.second.last-y.second.first+1));
            
        }
        return res;
    }

};