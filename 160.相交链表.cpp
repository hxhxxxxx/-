题目：
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
题目数据 保证 整个链式结构中不存在环。
注意，函数返回结果后，链表必须 保持其原始结构 。

解题思路：用哈希表记录第一个链表中的所有节点，然后遍历第二个链表，看哈希表中有无相同元素，有的话就返回


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>set;
        ListNode* p=headA;
        while(p!=NULL){
            set.insert(p);
            p=p->next;
        }
        p=headB;
        while(p!=NULL){
            if(set.count(p))return p;
            p=p->next;
        }
        return NULL;
    }
};



方法二：双指针

思路和算法

使用双指针的方法，可以将空间复杂度降至 O(1)O(1)O(1)。

只有当链表 headA\textit{headA}headA 和 headB\textit{headB}headB 都不为空时，两个链表才可能相交。因此首先判断链表 headA\textit{headA}headA 和 headB\textit{headB}headB 是否为空，如果其中至少有一个链表为空，则两个链表一定不相交，返回 null\text{null}null。

当链表 headA\textit{headA}headA 和 headB\textit{headB}headB 都不为空时，创建两个指针 pA\textit{pA}pA 和 pB\textit{pB}pB，初始时分别指向两个链表的头节点 headA\textit{headA}headA 和 headB\textit{headB}headB，然后将两个指针依次遍历两个链表的每个节点。具体做法如下：

每步操作需要同时更新指针 pA\textit{pA}pA 和 pB\textit{pB}pB。

如果指针 pA\textit{pA}pA 不为空，则将指针 pA\textit{pA}pA 移到下一个节点；如果指针 pB\textit{pB}pB 不为空，则将指针 pB\textit{pB}pB 移到下一个节点。

如果指针 pA\textit{pA}pA 为空，则将指针 pA\textit{pA}pA 移到链表 headB\textit{headB}headB 的头节点；如果指针 pB\textit{pB}pB 为空，则将指针 pB\textit{pB}pB 移到链表 headA\textit{headA}headA 的头节点。

当指针 pA\textit{pA}pA 和 pB\textit{pB}pB 指向同一个节点或者都为空时，返回它们指向的节点或者 null\text{null}null。

证明

下面提供双指针方法的正确性证明。考虑两种情况，第一种情况是两个链表相交，第二种情况是两个链表不相交。

情况一：两个链表相交

链表 headA\textit{headA}headA 和 headB\textit{headB}headB 的长度分别是 mmm 和 nnn。假设链表 headA\textit{headA}headA 的不相交部分有 aaa 个节点，链表 headB\textit{headB}headB 的不相交部分有 bbb 个节点，两个链表相交的部分有 ccc 个节点，则有 a+c=ma+c=ma+c=m，b+c=nb+c=nb+c=n。

如果 a=ba=ba=b，则两个指针会同时到达两个链表相交的节点，此时返回相交的节点；

如果 a≠ba \ne ba

=b，则指针 pA\textit{pA}pA 会遍历完链表 headA\textit{headA}headA，指针 pB\textit{pB}pB 会遍历完链表 headB\textit{headB}headB，两个指针不会同时到达链表的尾节点，然后指针 pA\textit{pA}pA 移到链表 headB\textit{headB}headB 的头节点，指针 pB\textit{pB}pB 移到链表 headA\textit{headA}headA 的头节点，然后两个指针继续移动，在指针 pA\textit{pA}pA 移动了 a+c+ba+c+ba+c+b 次、指针 pB\textit{pB}pB 移动了 b+c+ab+c+ab+c+a 次之后，两个指针会同时到达两个链表相交的节点，该节点也是两个指针第一次同时指向的节点，此时返回相交的节点。

情况二：两个链表不相交

链表 headA\textit{headA}headA 和 headB\textit{headB}headB 的长度分别是 mmm 和 nnn。考虑当 m=nm=nm=n 和 m≠nm \ne nm

=n 时，两个指针分别会如何移动：

如果 m=nm=nm=n，则两个指针会同时到达两个链表的尾节点，然后同时变成空值 null\text{null}null，此时返回 null\text{null}null；

如果 m≠nm \ne nm

=n，则由于两个链表没有公共节点，两个指针也不会同时到达两个链表的尾节点，因此两个指针都会遍历完两个链表，在指针 pA\textit{pA}pA 移动了 m+nm+nm+n 次、指针 pB\textit{pB}pB 移动了 n+mn+mn+m 次之后，两个指针会同时变成空值 null\text{null}null，此时返回 null\text{null}null。


简单来说，就是一个人走完了去另一个人那里走，它们必然会同时走到相同点上


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* p1=headA,*p2=headB;
       while(p1!=p2){
           p1=(p1==NULL)?headB:p1->next;
           p2=(p2==NULL)?headA:p2->next;
       }
       return p1;
    }
};

