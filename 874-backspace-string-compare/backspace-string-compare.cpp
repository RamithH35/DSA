class Solution {
public:
    string comparision(string s)
    {
        string res=s;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='#')
                res[j++]=s[i];
            else if(j>0)
                j--;
        }
        return res.substr(0,j);

    }
    bool backspaceCompare(string s, string t) {
        string res1=comparision(s);
        string res2=comparision(t);
        return (res1==res2);

    }
};