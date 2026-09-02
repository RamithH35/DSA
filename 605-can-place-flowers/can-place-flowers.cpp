class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size()==1&&flowerbed[0]==0)
            return flowerbed[0]==0?n<=1:n==0;
        int m=0;
        for(int i=0;i<flowerbed.size();i++)
        {
            if(m>=n) return true;
            if(i==0)
            {
                if(flowerbed[0]==0 && flowerbed[1]==0){
                flowerbed[0]=1;
                m++;
                }
            }
            else if(i==flowerbed.size()-1)
            {
                if(flowerbed[i]==0 && flowerbed[i-1]==0){
                flowerbed[i]=1;
                m++;
                }
            }
            else
            {
                if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0)
                {
                    m++;
                    flowerbed[i]=1;
                }
            }
        }
        return m>=n;
        
    }
};