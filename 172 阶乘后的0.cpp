题目：求阶乘后的值的零的个数
解题思路：最简单的方法就是去求完阶乘之后再判断0的个数
  但是这个方法会由于阶乘过大而溢出
class Solution {
public:
    int mul(int n){
        if(n==1)return 1;
        else return n*mul(n-1);
    }
    int trailingZeroes(int n) {
        if(n==0)return 0;
        int m=mul(n);
        int cnt=0;
        while(1){
            if(m%10==0){
                cnt++;
                m/=10;
            }else break;
        }
        return cnt;
    }
};
判断0的个数可以转换为2跟5的个数，由于2的质因子的个数肯定比5要多，所以只要找到5的个数即可
  
class Solution {
public:

    int trailingZeroes(int n) {
        int cnt=0;
        for(int i=5;i<=n;i=i+5){
            int t=i;
            while(t>=5){
                if(t%5==0){
                    cnt++;
                t/=5;
                }else break;  
            }
        }
        return cnt;
    }
};
