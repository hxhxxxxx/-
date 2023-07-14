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
