题目：找出字符串第一个匹配
这道题是经典的KMP算法的题目，不过KMP算法有点忘记了，这里就用简单的循环即可

class Solution {
public:
    int strStr(string haystack, string needle) {
        int siz1=haystack.size();
        int siz2=needle.size();
        if(siz1<siz2)return -1;
        for(int i=0;i<siz1-siz2+1;i++){
            int flag=0;
            for(int j=i;j<i+siz2;j++){
                if(haystack[j]!=needle[j-i]){
                    flag=1;
                    break;
                }
            }
            if(flag==0)return i;
        }
        return -1;
    }
};
