题目：给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

解题思路：用头插法即可

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead=new ListNode(0);
        ListNode* p=head;
        while(p!=nullptr){
            ListNode* t=p->next;
            p->next=newhead->next;
            newhead->next=p;
            p=t;
        }
        return newhead->next;
    }
};
