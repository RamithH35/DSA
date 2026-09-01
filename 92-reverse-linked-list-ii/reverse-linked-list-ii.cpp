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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || head->next==nullptr || left==right)
            return head;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *prev=dummy;
        ListNode *cur=head;
        int c=1;
        while(c!=left)
        {
            prev=cur;
            cur=cur->next;
            ++c;
        }
        ListNode *t=nullptr;
        ListNode *end=cur;
        while(c!=right+1)
        {
            ListNode *next=cur->next;
            cur->next=t;
            t=cur;
            cur=next;
            ++c;
        }
        end->next=cur;
        prev->next=t;
        return dummy->next;


    }
};