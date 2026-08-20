class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0,high=letters.size()-1;
        while(low<high)
        {
            int mid = (low+high)>>1;
            if(letters[mid]>target)
                high=mid;
            else
                low=mid+1;
        }
        if(letters[low]>target)
            return letters[low];
        return letters[0];
    }
};