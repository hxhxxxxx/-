题目：给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
如果可以，返回 true ；否则返回 false 。
magazine 中的每个字符只能在 ransomNote 中使用一次。

解题思路：把两个字符串中的字符储存个数，然后比较各个字符的数字大小

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len1=ransomNote.size();
        int len2=magazine.size();
        if(len1>len2)return false;
        vector<int>cnt(26,0);
        vector<int>c(26,0);
        for(int i=0;i<len2;i++){
            if(i<len1)cnt[ransomNote[i]-'a']++;
            c[magazine[i]-'a']++;
        }
        int flag=0;
        for(int i=0;i<26;i++){
            if(cnt[i]>c[i]){
                flag=1;
                break;
            }
        }
        if(flag)return false;
        else return true;
    }
};
