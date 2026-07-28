class Solution {
public:
    string smallestPalindrome(string s) {
       int n=s.size();
       vector<int>cmap(26,0);
       for(char c : s)
            cmap[c-'a']++;
        string left="";
        for(int i=0;i<cmap.size();i++)
        {
            if(cmap[i]>=2)
            {
                int pairs=cmap[i]/2;
                left.append(pairs,i+'a');
                cmap[i]%=2;
            }
        }
        string mid="";
        for(int i=0;i<cmap.size();i++)
        {
            if(cmap[i]==1)
            {
                mid.push_back(i+'a');
                break;
            }
        }
        string right=left;
        reverse(right.begin(),right.end());
        return left+mid+right;


    }
};