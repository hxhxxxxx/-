题目：给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

解题思路：先写一个翻转链表前K个元素，然后再往后走K步再翻转，直到不能翻转
用了上一题翻转链表的函数
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
    ListNode* reverse(ListNode* head, int k){
        ListNode* p=head;
        int cnt=0;
        ListNode* newhead=nullptr;
        while(cnt<k){
            if(!newhead){
                newhead=p;
                p=p->next;
            }else{
                ListNode* t=p->next;
                p->next=newhead;
                newhead=p;
                p=t;
            }
            cnt++;
        }
        head->next=p;
        return newhead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p=head;
        head=reverse(p,k);
        p=head;
        int cnt=0;
        while(cnt<k-1){
            p=p->next;
            cnt++;
        }
        while(1){
            ListNode* t=p;
            cnt=0;
            while(t){
                t=t->next;
                cnt++;
                if(cnt==k)break;
            }
            if(!t)break;
            if(cnt==k){
                ListNode* tmp=reverse(p->next,k);
                p->next=tmp;
                int num=0;
                while(num<k){
                    p=p->next;
                    num++;
                }
            }else break;
        }
        return head;
    }
};

21年版本
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
    void reverse(ListNode* p, ListNode* s, int k){
          ListNode* t;
          t=nullptr;
          ListNode* v;
          v=p;
          int cnt;
          cnt=k-1;
          while(cnt){
              ListNode* q,*u;
              if(v==s){
                 v->next=t; 
                 break;
              }
              q=v->next;
              if(t!=nullptr)v->next=t;
              if(q==s){
                 q->next=v; 
                 break;
              }
              u=q->next;
              q->next=v;
              t=q;
              v=u;
              cnt--;
          }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
    if(k==1)return head;
       ListNode* p;
       int cnt;
       p=head;
       ListNode* u;
       u=nullptr;
       while(p){
           ListNode* q;
           cnt=k-1;
           q=p;
           while(cnt&&q!=nullptr){
               q=q->next;
               cnt--;
           }
           if(cnt!=0||q==nullptr)break;
           ListNode* t;
           t=q->next;
           reverse(p,q,k);
           if(u!=nullptr)u->next=q;
           if(p==head)head=q;
           p->next=t;
           u=p;
           p=p->next;
       }
     return head;
    }
};
