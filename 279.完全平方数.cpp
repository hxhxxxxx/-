题目：给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

解题思路：用动态规划，每个数的最少数量，等于它剪去平方数的数的最小组成数加1的值

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int minn=i;
            for(int t=1;t*t<=i;t++){
                minn=min(minn,dp[i-t*t]+1);
            }
            dp[i]=minn;
        }
        return dp[n];
    }
};
