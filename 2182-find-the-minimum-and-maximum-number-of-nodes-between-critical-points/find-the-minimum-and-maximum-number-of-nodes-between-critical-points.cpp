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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int count=2;
        ListNode* prev=head;
        ListNode* cur=head->next;
        int first=-1;
        int last=-1;
        int mind=INT_MAX;
        vector<int>res;
        while(cur->next!=nullptr)
        {
            int p=prev->val;
            int c=cur->val;
            int n=cur->next->val;
            if((c<p && c<n)||(c>p && c>n))
            {
                if(first==-1)
                {
                    first=count;
                    last=count;
                }
                else
                {
                    mind=min(mind,count-last);
                    last=count;
                }
            }
            prev=cur;
            cur=cur->next;
            count+=1;
        }
        if(first==-1 || first==last)
                res={-1,-1};
            else
                res={mind,(last-first)};
            return res;

    }
};