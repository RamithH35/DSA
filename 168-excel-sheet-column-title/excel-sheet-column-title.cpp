class Solution {
public:
    string convertToTitle(int col) {
        string s="";
        while(col>0)
        {
            int rem=(col-1)%26;
            char c = 'A'+rem;
            s.push_back(c);
            col=(col-1)/26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};