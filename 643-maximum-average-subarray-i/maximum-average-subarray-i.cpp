class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        for(int i=0;i<k;i++)
            sum+=nums[i];
        double maxi=sum;
        int l=0;
        for(int i=k;i<nums.size();i++)
        {
            sum+=nums[i];
            sum-=nums[l];
            l++;
            maxi=max(maxi,sum);

        }
        return maxi/k;

    }
};