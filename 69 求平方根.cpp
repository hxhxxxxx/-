题目：求平方根的整数部分
解题思路：最简单的就是遍历，然后找到第一个平方大于x值，然后减一就是答案，优化版就是用二分查找去找值
class Solution {
public:
    int mySqrt(int x) {
        if(x==1)return 1;
        int i;
        for(i=1;i<x;i++){
            if((long long)i*i>x)break;
        }
        return i-1;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        if(x==1)return 1;
        int l=0,r=x,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if((long long)mid*mid<=x){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return ans;
    }
};
