题目：给定两个字符串 s 和 t ，判断它们是否是同构的。如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
这个方法就是相互映射判断有没有重复，如果重复就不行，但是我这个方法只考虑到了a-z没有考虑其他的
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char>ch(26,' ');
        vector<char>c(26,' ');
        int len=s.size();//遍历s
        int flag=0;
        for(int i=0;i<len;i++){
            cout<<i<<endl;
            if(ch[t[i]-'a']==' ')ch[t[i]-'a']=s[i];
            else if(ch[t[i]-'a']!=s[i]){
                flag=1;
                break;
            }
            if(c[s[i]-'a']==' ')c[s[i]-'a']=t[i];
            else if(c[s[i]-'a']!=t[i]){
                flag=1;
                break;
            }
        }
        if(flag)return false;
        else return true;
    }
};
为了解决这个问题，可以运用到哈希表，也是用上面相同的方法即可
这里用到了几个哈希表的方法

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>s2t;
        unordered_map<char,char>t2s;
        int len=s.size();
        for(int i=0;i<len;i++){
            char x=s[i];
            char y=t[i];
            if((s2t.count(x)&&s2t[x]!=y)||(t2s.count(y)&&t2s[y]!=x))return false;
            s2t[x]=y;
            t2s[y]=x;
        }
        return true;
    }
};
