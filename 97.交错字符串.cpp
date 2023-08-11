题目：给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
注意：a + b 意味着字符串 a 和 b 连接。

解题思路：最简单的想法是就哪个满足就选哪个,然后向后遍历，但是仔细想一个就知道当两个值一样的时候就可能遗漏掉某些情况

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.size();
        int l2=s2.size();
        int l3=s3.size();
        if((l1+l2)!=l3)return false;
        int i1=0,i2=0,i3=0;
        int flag=1;
        int sig=0;
        int prei1=-1,prei2=-1,prei3=-1;
        while(i1<l1&&i2<l2){
            
                if(s1[i1]==s3[i3]){}
                i1++;
                i3++;
            }else if(s2[i2]==s3[i3]){
                i2++;
                i3++;
            }else{
                return false;
            }
        }
        if(i1!=l1){
            while(i1<l1){
                if(s1[i1]==s3[i3]){
                    i1++;
                    i3++;
                }else return false;
            }
        }
        if(i2!=l2){
            while(i2<l2){
                if(s2[i2]==s3[i3]){
                    i2++;
                    i3++;
                }else return false;
            }
        }
        return true;
    }
};

所以需要用别的办法，用动态规划dp[i][j]记录从s1的i与 s2的j能否拼成s3的i+j

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.size();
        int l2=s2.size();
        int l3=s3.size();
        if((l1+l2)!=l3)return false;
        auto f=vector<vector<int>>(l1+1,vector<int>(l2+1,false));
        f[0][0]=true;
        for(int i=0;i<=l1;++i){
            for(int j=0;j<=l2;++j){
                int p=i+j-1;
                if(i>0){
                    f[i][j]|=(f[i-1][j]&&s1[i-1]==s3[p]);
                }
                if(j>0){
                    f[i][j]|=(f[i][j-1]&&s2[j-1]==s3[p]);
                }
            }
        }
        return f[l1][l2];
    }
};
不过也可以提前先把两个边界处理了之后再处理中间的，这样就不用考虑边界的问题，少了两个判断

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
       int siz1=s1.size();
       int siz2=s2.size();
       int siz3=s3.size();
       if(siz3!=(siz1+siz2))return false;
       if(siz3==0)return true;
       int dp[siz2+1][siz1+1];
       memset(dp,0,sizeof (dp));
       int i,j;
       for(i=0;i<siz1;i++){
           if(s1[i]==s3[i])dp[0][i+1]=1;
           else break;
       }
       for(i=0;i<siz2;i++){
           if(s2[i]==s3[i])dp[i+1][0]=1;
           else break;
       }
       for(i=1;i<=siz2;i++){
           for(j=1;j<=siz1;j++){
               if((dp[i-1][j]==1&&s3[i+j-1]==s2[i-1])||(dp[i][j-1]==1&&s3[i+j-1]==s1[j-1]))dp[i][j]=1;
           }
       }
        if(dp[siz2][siz1]==1)return true;
        else return false;
    }
};




