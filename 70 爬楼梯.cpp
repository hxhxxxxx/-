题目：爬楼梯的可能数
解题思路：动态规划，某一层的可能性等于前两层的数量之和，因为某一层楼梯只能从前一层跟前两层跳过去

class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};
不过这样直接做会超时，因为会到后面会超时，有很多重复的地方，所以可以用哈希表储存之前的信息，这样就可以防止重复工作
class Solution {
public:
    unordered_map<int,int>m;
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        m[1]=1;
        m[2]=2;
        for(int i=3;i<=n;i++){
            m[i]=m[i-1]+m[i-2];
        }
        return m[n];
    }
};
