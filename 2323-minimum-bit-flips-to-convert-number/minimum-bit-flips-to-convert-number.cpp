class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long ans=start^goal;
        long cnt=0;
        while(ans>0)
        {
            if(ans&1)
                cnt++;
            ans=ans>>1;
        }
        return cnt;
    }
};