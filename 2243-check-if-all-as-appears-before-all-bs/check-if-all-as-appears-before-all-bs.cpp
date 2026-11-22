class Solution {
public:
    bool checkString(string s) {
        bool seen=false;
        for(char c:s)
        {
            if(c=='a' && seen)
                return false;
            else if(c=='b')
                seen=true;
        }
        return true;
    }
};