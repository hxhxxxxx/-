题目：就是上面这个标题
解题思路：对n的正负性进行判断，然后分类讨论
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)return 0.0;
        double t;
        if(n>0){
                t=x;
                for(int i=1;i<n;i++)t*=x;
        }else{
            t=1.0/x;
            for(int i=1;i<-n;i++)t*=t;
        }
        return t;
    }
};
上面的做法会遇到一个问题，因为对于分数相乘可能会导致误差比较大，所以应该先乘了之后再用1相除
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)return 0.0;
        if(n==0)return 1.0;
        if(n==1)return x;
        double t;
        if(n>0){
                t=x;
                for(int i=1;i<n;i++)t*=x;
        }else{
            t=x;
            for(int i=1;i<-n;i++)t*=x;
            t=1/t;
        }
        return t;
    }
};
不过这个方法对于n比较小的情况是可以应对的，但是对于n比较大的时候会超时，所以需要别的方法
也就是要快速相乘，不要一个一个x相乘，用快排的思路，一半一半地乘

class Solution {
public:
    double quickmul(double x,int n){
        if(n==0)return 1.0;
        double y=quickmul(x,n/2);
        return (n%2)?y*y*x:y*y;
    }
    double myPow(double x, int n) {
        long long N=n;
        return (N>0)?quickmul(x,N):1.0/quickmul(x,-N);
    }
};
