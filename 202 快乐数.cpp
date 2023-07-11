题目：编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」 定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

解题思路：这题是判断循环，主要问题就是如何让循环停止
那首先先分类一下
  1.循环到1
  2.循环到其他
  3.一直无限增长
但是第三种情况可以排出，因为最大的三位数999，按快乐数的方法来算，也只有243，所以不会无限增长
那么就是判断两种循环即可
这里就运用到了哈希表，把出现过的数放在哈希表中，然后在后续判断中，如果在哈希表中出现过，那么就意味着进入了循环，这样就可以让循环停止
class Solution {
public:
    int getnext(int n){
        int t=0;
        while(n>0){
            int m=n%10;
            t+=m*m;
            n=n/10;
        }
        return t;
    }
    bool isHappy(int n) {
        unordered_map<int,int>m;
        while(n!=1&&!m.count(n)){
            m[n]=1;
            n=getnext(n);
        }
        return n==1;
    }
};
小改一部分，让乘方的运算简化一下
class Solution {
public:
    int a[10]={0,1,4,9,16,25,36,49,64,81};
    int getnext(int n){
        int t=0;
        while(n>0){
            int m=n%10;
            t+=a[m];
            n=n/10;
        }
        return t;
    }
    bool isHappy(int n) {
        unordered_map<int,int>m;
        while(n!=1&&!m.count(n)){
            m[n]=1;
            n=getnext(n);
        }
        return n==1;
    }
};
