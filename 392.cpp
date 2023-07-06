题目：判断子序列
解题思路：在遍历大的字符串的过程中，来判断有无小的字符串匹配，然后推进即可

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int siz1=s.size();
        int siz2=t.size();
        int j=0;
        for(int i=0;i<siz2;i++){
            if(s[j]==t[i]){
                j++;
                if(j==siz1)return true;
            }
        }
        if(j==siz1)return true;
        else return false;
    }
};
