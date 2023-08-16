题目：判断链表中有没有环，如果有那么找到环中的入口处

解题思路：用快慢指针去遍历，如果两个指针相遇，那么存在环，否则没有环

至于如何判断环的入口处

现在设三个值，从头到入口的距离为a,从入口到相遇处的距离为b,剩下环的距离为c

在二者相遇时，肯定是第一次相遇，否则在环内如果是多次相遇，由于快指针的距离是慢指针距离的两倍，所以之前肯定遇到过
在这个基础上，再根据距离的两倍关系，得到公式:2*(a+b)=a+n*(b+c)+b   n为圈数
a=(n-1)(b+c)+c
由这个公式可以知道，慢指针从相遇点出发，如果有一个新的点从头节点同时出发，二者会在环的入口相遇，因为a等于n-1圈加环中剩下的长度c
在得到了这个条件后，就可以书写代码

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head,*fast=head;
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast!=NULL)fast=fast->next;
            if(slow==fast)break;
        }
        if(fast==NULL)return NULL;
        ListNode* p=head;
        while(p!=slow){
            p=p->next;
            slow=slow->next;
        }  
        return p;
    }
};
