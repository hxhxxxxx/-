题目：合并两个有序链表
解题思路：也是根据上一题的想法，这样会比较方便一点，让代码量比较少
class Solution {
public:
    int min(int x,int y){
        if(x<y)return x;
        else return y;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=nullptr, *tail=nullptr;
        while(list1||list2){
            int n1= list1? list1->val:101;//如果不存在就赋予超大值，这样下面就不可能会被选到
            int n2=list2?list2->val:101;
            int val=min(n1,n2);
            if(!head){
                head=tail=new ListNode(val);
            }else{
                tail->next=new ListNode(val);
                tail=tail->next;
            }
            if(list1&&val==list1->val){
                list1=list1->next;
                continue;//因为可能两个值相同，所以在前一个处理的时候需要跳过下面的判断，不然会让长度变小，不过如果需要去重的话就可以不用这个continue
            }
            if(list2&&val==list2->val)list2=list2->next;
        }
        return head;
    }
};
