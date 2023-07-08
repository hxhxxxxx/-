题目：给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
解题思路：也是跟之前的方法一样，就是稍微处理一下字符串中的单词，然后再跟上面一道题的处理方法相同
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>m;
        unordered_map<string,char>s2c;
        int siz=s.size();
        int len=pattern.size();
        string t="";
        int pre=0;
        for(int i=0;i<siz;i++){
            if(s[i]==' '){
                if(m.count(pattern[pre])&&m[pattern[pre]]!=t)return false;
                if(s2c.count(t)&&s2c[t]!=pattern[pre])return false;
                s2c[t]=pattern[pre];
                m[pattern[pre]]=t;
                pre++;
                t="";
                continue;
            }
            t+=s[i];
        }
        if(m.count(pattern[pre])&&m[pattern[pre]]!=t)return false;
        if(s2c.count(t)&&s2c[t]!=pattern[pre])return false;
        if(pre!=len-1)return false;
        return true;
    }
};
