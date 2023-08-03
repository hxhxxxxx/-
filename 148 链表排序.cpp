题目：给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
     时间复杂度为O(nlogn)

解题思路：用快慢指针将链表分成两个部分，然后将这个两个部分用迭代排好序，再将两个排好序的链表按升序再按照排好序合并
        唯一需要注意的点就是分成两个链表的时候，需要注意排好序的链表最后一个元素的next指针需要指向空指针，否则在排序过程中会死循环

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mysort(head,nullptr);
    }
    ListNode* mysort(ListNode* head,ListNode* tail){
        if(head==nullptr)return nullptr;
        if(head->next==tail){
            head->next=nullptr;//为了之后排序用，否则会死循环
            return head;
        }
        ListNode* fast=head,* slow=head;
        while(fast!=tail){
            fast=fast->next;
            slow=slow->next;
            if(fast!=tail)fast=fast->next;
        }
        ListNode* mid=slow;
        return merge(mysort(head,mid),mysort(mid,tail));
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* head=new ListNode(0);
        ListNode* tmp=head,* tmp1=head1,*tmp2=head2;
        while(tmp1&&tmp2){
            if(tmp1->val<=tmp2->val){
                tmp->next=tmp1;
                tmp1=tmp1->next;
            }else{
                tmp->next=tmp2;
                tmp2=tmp2->next;
            }
            tmp=tmp->next;
        }
        if(tmp1){
            tmp->next=tmp1;
        }
        if(tmp2){
            tmp->next=tmp2;
        }
        return head->next;
    }
};
