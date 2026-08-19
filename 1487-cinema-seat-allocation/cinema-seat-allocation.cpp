class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>>mp;
        for(auto &seat:reservedSeats)
            mp[seat[0]].insert(seat[1]);
        int total=2*n;
        for(auto &[row,seats]:mp)
        {
            bool left=true;
            bool right=true;
            bool mid=true;
            for(auto &x:seats)
            {
                if(x>=2 && x<=5)
                    left=false;
                if(x>=4 && x<=7)
                    mid=false;
                if(x>=6 && x<=9)
                    right=false;
            }
            if(left&&right)
                continue;
            else if(left||mid||right)
                total=total-1;
            else 
                total=total-2;

        }
        return total;
    }
};