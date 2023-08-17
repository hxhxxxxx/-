题目：给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
     假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
     你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

解题思路：把数组看成是链表，nums[i]代表i的下一个指向的数，由于有两个以上的相同的数，所以代表链表有环，并且环的入口即为那个重复数，这样问题就转化成了找链表中的环入口

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        slow=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }    
        return slow;
    }
};
