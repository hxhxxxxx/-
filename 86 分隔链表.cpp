题目：给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
      你应当 保留 两个分区中每个节点的初始相对位置
解题思路：就是遍历链表把小的放在前面，需要用几个指针来标注一下位置，比如小的节点的最后一个位置，以及当前遍历位置跟前一位置，方便移动
        还有就是要处理一下特殊情况，比如刚开始都是大于等于x的时候，要找到一个比x小的值先放到最前面，然后就可以一样的方法来处理

也有两个版本，21年与23年
  先是23年版的，就是按照我上面写的思路
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* p=head;
        ListNode* q=p;
        ListNode* t=head;
        while(p&&p->val<x){
            q=p;
            p=p->next;
        }
        if(!p)return head;
        if(p==head&&p->val>=x){
            while(p->next&&p->next->val>=x){
                p=p->next;
            }
            if(!p->next)return head;
            q=p->next;
            p->next=p->next->next;
            q->next=head;
            head=q;
            t=p;
            p=p->next;
        }
        if(q->next==p)t=q;
        while(p){
            if(p->val>=x){
                t=p;
                p=p->next;
            }else{
                t->next=p->next;
                p->next=q->next;
                q->next=p;
                q=q->next;
                p=t->next;
            }
        }
        return head;
    }
};
然后是21年版的，该写法没有提前进行处理，导致分类讨论就多，代码会看着比较复杂，也多了一些判断
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr||head->next==nullptr)return head;
       ListNode* p;
       ListNode* head1=nullptr;
       p=head;
       ListNode* l;
       l=p;
       ListNode* q;
       while(p!=nullptr){
           if(p->val<x){
               l=p;
               p=p->next;
           }else{
              if(head1==nullptr){
                  head1=p;
                  q=head1;
                  if(l==p){
                      head=head->next;
                      p=head;
                      l=p;
                  }else{
                    l->next=p->next;
                    p=p->next;
                  }
                  q->next=nullptr;
              }else{
                  q->next=p;
                  if(l==p){
                      head=head->next;
                      p=head;
                      l=p;
                  }else{
                    l->next=p->next;
                    p=p->next;
                  }
                  q=q->next;
                  q->next=nullptr;
              }
            }
       }
       if(l==nullptr)return head1;
       l->next=head1;
       return head;
    }
};
