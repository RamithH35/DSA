class Solution {
public:
    string removeDigit(string number, char digit) {
        int last=-1;
        for(int i=0;i<number.size();i++)
        {
            if(number[i]==digit)
            {
                last=i;
                if(i+1<number.size()&&number[i+1]>number[i])
                    return number.substr(0,i)+number.substr(i+1);
            }
        }
        
        return number.substr(0,last)+number.substr(last+1);
    }
};