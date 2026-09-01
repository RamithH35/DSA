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
    ListNode* reversell(ListNode *head)
    {
        ListNode *temp=head;
        ListNode *prev=nullptr;
        while(temp)
        {
            ListNode *next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || head->next==nullptr || left==right)
            return head;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *prev=dummy;
        ListNode *cur=head;
        ListNode *start=head;
        ListNode *end=head;
        int c=1;
        while(c!=left)
        {
            prev=cur;
            cur=cur->next;
            ++c;
        }
        prev->next=nullptr;
        start=cur;
        while(c!=right)
        {
            cur=cur->next;
            ++c;
        }
        end=cur;
        cur=cur->next;
        end->next=nullptr;
        end=reversell(start);
        prev->next=end;
        start->next=cur;
        return dummy->next;


    }
};