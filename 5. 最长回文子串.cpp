题目：给你一个字符串 s，找到 s 中最长的回文子串。如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

解题思路：用动态规划的思路，从长度出发，对于不同长度然后判断最左最右的字符是否相同，然后判断中间是否是回文子串即可

class Solution {
public:
    string longestPalindrome(string s) {
        int siz=s.size();
        vector<vector<int>>dp(siz,vector<int>(siz));
        int begin=0;
        int maxL=1;
        for(int i=0;i<siz;i++)dp[i][i]=1;
        for(int L=2;L<=siz;L++){
            for(int i=0;i<=siz-L;i++){
                int j=i+L-1;
                if(L==2){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                        if(L>maxL){
                            begin=i;
                            maxL=L;
                        }
                        }
                }else{
                    if(s[i]==s[j]&&dp[i+1][j-1]){
                        dp[i][j]=1;
                        if(L>maxL){
                            begin=i;
                            maxL=L;
                        }
                        }
                }
            }
        }
        return s.substr(begin,maxL);
    }
};
