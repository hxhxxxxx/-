题目：两数之和
解题思路：我这样设置的不好，需要考虑的特殊情况过多

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;
        ListNode* p2=l2;
        int forw=0;
        while(p1&&p2){
            int t=p1->val+p2->val+forw;
            p1->val=t%10;
            forw=t/10;
            if(!p1->next||!p2->next)break;
            p1=p1->next;
            p2=p2->next;
        }
        if(!p1->next){
            if(!p2->next){
                if(forw==1){
                    ListNode* t=new ListNode(1,nullptr);
                    p1->next=t;
                }
            }else{
                p1->next=p2->next;
                p2=p2->next;
                if(p2->val==9){
                    while(p2->val==9&&forw==1){
                    p2->val=0;
                    if(!p2->next){
                        ListNode* t=new ListNode(0,nullptr);
                        p2->next=t;
                        p2=p2->next;
                    }else{
                         p2=p2->next;
                         if(p2->val!=9){
                              p2->val+=forw;
                              break;
                         }
                         continue;
                    }
                    p2->val+=forw;
                    if(p2->val==10){
                        p2->val=0;
                        ListNode* t=new ListNode(1,nullptr);
                        p2->next=t;
                    }
                }
                }else p2->val+=forw;
            } 
        }else{
            p1=p1->next;
            if(p1->val==9){
                while(p1->val==9&&forw==1){
                p1->val=0;
                if(!p1->next){
                        ListNode* t=new ListNode(0,nullptr);
                        p1->next=t;
                        p1=p1->next;
                    }else{
                         p1=p1->next;
                         continue;
                    }
            }
            p1->val+=forw;
            if(p1->val==10){
                        p1->val=0;
                        ListNode* t=new ListNode(1,nullptr);
                        p1->next=t;
                    }
            }else p1->val+=forw;
            
        }
        return l1;
    }
};

参考了一下参考答案的思路，就是不妨把两个链表当成相同的长度，这样的话就可以不用像我上面那样还要对后续进行处理，反而更加麻烦
这个思路确实很不错
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=nullptr,*tail = nullptr;
        int carry=0;
        while(l1||l2){
            int n1=l1 ? l1->val:0;//节点为空就当成是0
            int n2=l2 ? l2->val:0;
            int sum=n1+n2+carry;
            if(!head){
                head=tail=new ListNode(sum%10);
            }else{
                tail->next=new ListNode(sum%10);
                tail=tail->next;
            }
            carry=sum/10;
            if(l1)l1=l1->next;//让链表往后走
            if(l2)l2=l2->next;
        }
        if(carry>0)tail->next=new ListNode(carry);
        return head;
    }
};
