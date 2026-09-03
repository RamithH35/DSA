class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd=INT_MAX;
        int mindex=-1;
        int secondmin=INT_MAX;
        for(int i=0;i<nums1.size();i++)
        {
            int x=nums1[i];
            if(x%2)
            {
                if(x<minodd)
                {
                    secondmin=min(secondmin,minodd);
                    minodd=x;
                    mindex=i;

                }
                else
                    secondmin=min(x,secondmin);
            }
        }
        bool flagodd=true;
        bool flageven=true;
        for(int j=0;j<nums1.size();j++)
        {
            if(nums1[j]%2)
                continue;
            if(j!=mindex && nums1[j]-minodd >=1)
                continue;
            else if(nums1[j]-secondmin >=1)
                continue;
            flagodd=false;
            break;
                        
        }
        for(int j=0;j<nums1.size();j++)
        {
            if(nums1[j]%2==0)
                continue;
            if(j!=mindex && nums1[j]-minodd >=1)
                continue;
            else if(nums1[j]-secondmin >=1)
                continue;
            flageven=false;
            break;
                        
        }
        return (flagodd || flageven);

        
    }
};