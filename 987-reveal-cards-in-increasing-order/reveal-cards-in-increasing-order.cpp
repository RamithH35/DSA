class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int>q;
        vector<int>res;
        vector<int>ans(deck.size());
        for(int i=0;i<deck.size();i++)
            q.push(i);
        while(!q.empty())
        {
            res.push_back(q.front());q.pop();
            if(q.empty())
                break;
            int x=q.front();q.pop();
            q.push(x);
        }
        int count = 0;
        for (int x : res)
            ans[x]=deck[count++];
        return ans;
    }
};