题目：给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

解题思路：先找到翻转的位置，用头插法进行翻转链表，然后再连接
这里也是有两版， 21年与23年，23年由于看到k组的翻转，所以想提前用类似的思路处理一下，所以分开写了一个函数

下面是21年版的
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {        if(left==right)return head;
         int cnt=1;
         ListNode* p;
         ListNode* s;
         ListNode* t;
         p=head;
         //left==1. right=left+1
         while(cnt<left-1){
             p=p->next;
             cnt++;
         }
         s=p;
         if(left!=1){
             p=p->next;
             cnt++;
         }
         ListNode* head0;
         head0=p;
         t=head0;
         p=p->next;
         head0->next=nullptr;
         ListNode* next;
         while(cnt<right){
            next=p->next;
            p->next=head0;
            head0=p;
            p=next;
            cnt++;
         }
         t->next=p;
         if(left==1)return head0;
         s->next=head0;
         return head;
    }
};

下面是23年版
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
    void prtl(ListNode* head){
        while(head){
            cout<<head->val<<endl;
            head=head->next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        ListNode* p=head;
        int cnt=1;
        while(cnt<left-1){
            p=p->next;
            cnt++;
        }//停留在翻转前
        if(left==1){
          ListNode* newhead=reverse(p,right-left+1);  
          return newhead;
        }else{
            ListNode* newhead=reverse(p->next,right-left+1);
            p->next=newhead;
        }
        return head;
    }
};
