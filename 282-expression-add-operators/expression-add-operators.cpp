class Solution {
public:
    void helper(string &s,int index,long long ans,long long prev,string &num,long long target,vector<string>&res)
    {
        if(index==num.size())
        {
            if(ans==target)
                res.push_back(s);
            return;
        }
        long long x=0;
        for(int i=index;i<num.size();i++)
        {
            if(i>index && num[index]=='0')
                break;
            x= (x*10)+(num[i]-'0');
            string part = num.substr(index,i-index+1);
            int len=part.size();
            if(index==0)
            {
                s+=part;
                helper(s,i+1,x,x,num,target,res);
                s.erase(s.size()-len);
            }
            else
            {
                s+='+'+part;
                helper(s,i+1,ans+x,x,num,target,res);
                s.erase(s.size()-len-1);
                s+='-'+part;
                helper(s,i+1,ans-x,-x,num,target,res);
                s.erase(s.size()-len-1);
                s+='*'+part;
                helper(s,i+1,ans-prev+prev*x,prev*x,num,target,res);
                s.erase(s.size()-len-1);
            }

        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string>res;
        string s;
        helper(s,0,0,0,num,target,res);
        return res;
    }
};