题目：判断是否存在环形链表
解题思路：原来就想到哈希表，但是忘记可以直接对节点存储，之前以为对数值存储不行
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>set;
        ListNode* p=head;
        if(!head)return false;
        while(p){
            if(set.count(p))return true;
            set.insert(p);
            p=p->next;
        }
        return false;
    }
};
或者用经典的龟兔赛跑的思想，设置两个快慢指针，然后来跑图，如果存在环，那么经过一定的步数，肯定会套圈
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
    bool hasCycle(ListNode *head) {
        if(!head||!head->next)return false;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(slow!=fast){
            if(!fast||!fast->next)return false;
            fast=fast->next->next;
            slow=slow->next;
        }
        return true;
    }
};
