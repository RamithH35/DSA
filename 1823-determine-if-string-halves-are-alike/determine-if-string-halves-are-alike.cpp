class Solution {
public:
    bool halvesAreAlike(string s) {
        int a=0;
        int b=0;
        int n=s.size()/2;
        string s1=s.substr(0,n);
        string s2=s.substr(n);
        for(char c:s1)
        {
            c=tolower(c);
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                a++;
        }
        for(char c:s2)
        {
            c=tolower(c);
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                b++;
        }
        return a==b;
    }
};