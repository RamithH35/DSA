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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode *dh=new ListNode(-1);
        ListNode *dt=new ListNode(-1);
        ListNode *t1=dh,*t2=dt;
        ListNode *cur=head;
        while(cur!=nullptr)
        {
            if(cur->val<x)
            {
                t1->next=cur;
                t1=cur;
            }
            else
            {
                t2->next=cur;
                t2=cur;
            }
            cur=cur->next;
        }
        t2->next=nullptr;
        if(dh->next==nullptr && dt->next)
            return dt->next;
        t1->next=dt->next;
        return dh->next;
    }
};