题目：判断一个数字是否为回文数
解题思路：如果是正数只需要倒置一下即可
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x==0)return true;
        int t=x;
        double y=0;
        while(t>0){
            y=y*10+t%10;
            t=t/10;
        }
        if(x==y)return true;
        else return false;
    }
};
