class Solution {
public:
    string smallestPalindrome(string s) {
       int n=s.size();
       vector<int>cmap(26,0);
       for(char c : s)
            cmap[c-'a']++;
        string left="";
        string mid="";
        for(int i=0;i<cmap.size();i++)
        {
            left +=string(cmap[i]/2,(char)('a'+i));
            if(cmap[i]%2==1)
                mid=(char)('a'+i);
        }
        string right=left;
        reverse(right.begin(),right.end());
        return left+mid+right;


    }
};