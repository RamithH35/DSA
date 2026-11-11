class Solution {
public:
    vector<string> helper(vector<string>&product,string &s)
    {
        int low=0;
        int high=product.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            string t=product[mid].substr(0,s.size());
            if(t<s)
                low=mid+1;
            else if(t>=s)
                high=mid-1;

        }
        vector<string>temp;
        for(int i=low;i<product.size() && temp.size()<3;i++)
        {
            if(product[i].substr(0,s.size())!=s)
                break;
            temp.push_back(product[i]);
        }
        return temp;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>res;
        sort(products.begin(),products.end());
        for(int i=1;i<=searchWord.size();i++)
        {
            string s=searchWord.substr(0,i);
            vector<string>temp=helper(products,s);
            res.push_back(temp);
        }
        return res;
    }
};