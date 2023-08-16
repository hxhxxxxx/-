题目：判断链表是否为回文链表

解题思路：该题的方法有很多，比如找到中间的值，然后翻转前半部分跟后半部分比较，或者存到数组中，用数组来进行判断
我才用了快慢指针的方法，然后把前半部分的值存下来，在遍历后半部分的时候跟数组中进行对比即可，这样的时间复杂度为O(n),而且只遍历了一次链表

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head;
        int flag=0;
        vector<int>t;
        if(head==nullptr||head->next==nullptr)return true;
        while(fast!=nullptr){
            t.push_back(slow->val);
            slow=slow->next;
            fast=fast->next;
            if(fast!=nullptr){
                fast=fast->next;
                if(fast==nullptr)flag=1;//判断奇偶性，如果flag=1，那么链表长度为偶数
                }
        }
        if(!flag){
            //如果是奇数的话，slow会停在后半段
            t.pop_back();//弹出中间的数
            }
        while(slow!=nullptr){
                int tmp=t[t.size()-1];
                if(slow->val!=tmp)return false;
                t.pop_back();
                slow=slow->next;
            }
        return true;
    }
};
