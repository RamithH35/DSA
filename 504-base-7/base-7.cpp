class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)
            return "0";
        string ans="";
        bool isneg=(num<0)?true:false;
        num=abs(num);
        while(num>0)
        {
            int remainder=num%7;
            ans = char('0'+remainder)+ans;
            num=num/7;
        }
        return (isneg)?("-"+ans):ans;
    }
};