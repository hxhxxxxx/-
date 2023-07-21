题目：求最长递增子序列
解题思路：采用的是动态规划的思路，使用数组记录以当前位置为结尾的最长子序列的长度，这样后面的递归只需要比较nums的值，再记录最长的长度，最后加1即可
        然后再遍历一遍来寻找最大长度
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        if(len==0)return 0;
        vector<int>dp(len,1);
        for(int i=1;i<len;i++){
            int max=0;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&dp[j]>max)max=dp[j];
            }
            dp[i]=max+1;
        }
        int max=0;
        for(int i=0;i<len;i++)if(max<dp[i])max=dp[i];
        return max;
    }
};
