题目：给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 

解题思路：先遍历一次链表，用哈希表记录每个值出现的次数，然后第二次遍历过程中，遇到出现过多次的，把该节点删除即可

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int>m;
        ListNode* p=head;
        while(p){
            m[p->val]++;
            p=p->next;
        }
        p=head;
        ListNode* q=p;
        while(p){
            if(m[p->val]!=1){
                if(p==head){
                    head=head->next;
                    p=head;
                    q=p;
                }else{
                    p=p->next;
                    q->next=p;
                }
            }else{
                q=p;
                p=p->next;
            }
        }
        return head;
    }
};

不过该方法没有用已经排好序的方法，是一种通用的方法，不过用额外占用O(n)的空间，且时间较长
官方给出的方法如下，设置一个头节点，然后去判断

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0, head);

        ListNode* cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};
