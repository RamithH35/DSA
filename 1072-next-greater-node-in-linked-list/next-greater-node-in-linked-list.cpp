/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        stack<pair<int,int>>st;
        int ind=0;
        ListNode* cur=head;
        while(cur)
        {
            ans.push_back(0);
            while(!st.empty()&&st.top().first<cur->val)
            {
                int index=st.top().second;
                ans[index]=cur->val;
                st.pop();

            }
            st.push({cur->val,ind});
            cur=cur->next;
            ind++;
        }
        while(!st.empty())
        {
            ans[st.top().second]=0;
            st.pop();
        }
        return ans;
    }
};