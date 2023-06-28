//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//判断你是否能够到达最后一个下标。

//拿到的第一想法是动态规划，首先也是建立一个数组a[n]，a[i]表示在第i个的位置上可以到达的最远位置，但是略显复杂，没有想到递推公式
//这道题的思路可以转化为可以到达的最远的距离，然后再判断这个距离是否比下标最大值大
//而怎么判断是不是最远，可以在当前的最大的往前走，没走一步先让可以走的距离减1，然后跟当前位置的距离相比，如果比它大就继续走，否则就换成当前位置即可
//当停止的时候，看看是不是在最后的位置

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int siz;
        siz=nums.size();
        if(siz==0||siz==1)return true;
        int i=1;
        int tmp=nums[0];
        while(i<siz){
            if(tmp==0)break;
            tmp--;
            if(tmp<nums[i])tmp=nums[i];
            i++;
        }
        if(i==siz)return true;
        else return false;
    }
};
