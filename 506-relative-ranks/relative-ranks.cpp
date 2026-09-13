class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        vector<string>result(score.size());
        for(int i=0;i<score.size();i++)
            pq.push({score[i],i});
        int count=1;
        while(pq.size())
        {
            if(count<=3)
            {
                string res="";
                if(count==1)
                    res="Gold Medal";
                else if(count==2)
                    res="Silver Medal";
                else 
                    res="Bronze Medal";
                int index=pq.top().second;
                pq.pop();
                result[index]=res;
                count++;
            }
            else
            {
                string res=to_string(count);
                count++;
                int index=pq.top().second;
                pq.pop();
                result[index]=res;

            }
        }
        return result;
        
    }
};