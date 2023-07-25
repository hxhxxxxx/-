题目：给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

解题思路：用哈希表记录位置，经过一次遍历后改变即可

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        unordered_map<int,ListNode*>m;
        ListNode* p=head;
        int cnt=1;
        while(p){
            m[cnt++]=p;
            p=p->next;
        }
        cnt=cnt-n;
        if(cnt==1){
            head=head->next;
            return head;
        }
        ListNode* t=m[cnt]->next;
        m[cnt-1]->next=t;
        return head;
    }
};

不过更为巧妙的方法，就是类似快慢指针
用双指针的方法
先让一个指针走N步，然后第二个指针再走，当第一个指针走到底的时候，第二个指针就到了该到的位置
这里具体处理，由于要删除一个节点，所以走到节点前的一个位置即可，方便进行删除

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p,*q;
        p=head;
        q=head;
        while(n--)q=q->next;
        if(q==nullptr){
            return head->next;
        }else{
            while(q->next){
            q=q->next;
            p=p->next;
        }
        p->next=p->next->next;
        }
        
        return head;
    }
};




