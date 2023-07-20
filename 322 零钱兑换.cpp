题目：零钱兑换给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。
解题思路：使用动态规划，子问题就是整数k有几种可能，那么只要把整数k减去coins数组中的可能，再去判断有没有值，并且是不是最小即可
class Solution {
public:
    int min(int x,int y){
        if(x<y)return x;
        else return y;
    }
    int coinChange(vector<int>& coins, int amount) {
        auto dp=vector<int>(amount+1,-1);
        dp[0]=0;
        int siz=coins.size();
        for(int i=1;i<=amount;i++){
            for(int j=siz-1;j>=0;j--){
                if(coins[j]>i)continue;
                if(dp[i-coins[j]]!=-1){
                    if(dp[i]==-1)dp[i]=dp[i-coins[j]]+1;
                    else dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount];
    }
};
