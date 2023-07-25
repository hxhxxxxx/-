题目：给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
解题思路：也是用哈希表记录位置，然后再调整链表即可
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        unordered_map<int,ListNode*>m;
        int cnt=1;
        ListNode* p=head;
        while(p){
            m[cnt]=p;
            p=p->next;
            cnt++;
        }
        cnt--;
        if(cnt==0||cnt==1)return head;
        k=k%cnt;
        if(k==0)return head;
        head=m[cnt-k+1];
        m[cnt]->next=m[1];
        m[cnt-k]->next=nullptr;
        return head;
    }
};

官方思路，也是我之前没想到的，因为k值可能会大于链表长度，所以不能像删除最后第k个节点那样
但是官方给出思路可以将链表头尾相连，就可以解决该问题

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        int n = 1;
        ListNode* iter = head;
        while (iter->next != nullptr) {
            iter = iter->next;
            n++;
        }
        int add = n - k % n;
        if (add == n) {
            return head;
        }
        iter->next = head;
        while (add--) {
            iter = iter->next;
        }
        ListNode* ret = iter->next;
        iter->next = nullptr;
        return ret;
    }
};
