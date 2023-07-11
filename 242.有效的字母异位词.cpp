题目：看两个字符串中各个字符个数是否相同
解题思路：只需要简单地遍历即可
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>a(26,0);
        vector<int>b(26,0);
        int siz1=s.size();
        int siz2=t.size();
        if(siz1!=siz2)return false;
        for(int i=0;i<siz1;i++){
            a[s[i]-'a']+=1;
            b[t[i]-'a']+=1;
        }
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
};
