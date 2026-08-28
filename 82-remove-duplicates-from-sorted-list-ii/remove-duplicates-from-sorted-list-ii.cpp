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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        ListNode *prev=dummy;
        ListNode *cur=head;
        while(prev->next!=nullptr)
        {
            if(cur->next!=nullptr && cur->val==cur->next->val)
            {
                int d=cur->val;
                cur=cur->next->next;
                while(cur!=nullptr && cur->val==d)
                    cur=cur->next;
                prev->next=cur;
            }
            else
            {
                prev=cur;
                cur=cur->next;
            }
            
        }
        return dummy->next;
    }
};