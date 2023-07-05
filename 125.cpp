题目：验证回文串
解题思路：主要是先处理空格，然后再把大小写转换一下，最后再反转一下字符串，比较二者是否相等即可
不过按照这个思路的做法，在后面出现了超过内存限制，得考虑一些别的方法，这可能是跟我写了其他函数，用了新的储存有关，可以直接在s上进行处理
class Solution {
public:
    string trans(string s){
        int siz=s.size();
        string t=s;
        for(int i=0;i<siz;i++){
            if('A'<=s[i]&&s[i]<='Z')t[i]=t[i]-'A'+'a';
        }
        return t;
    }
    string del(string s){
        int siz=s.size();
        string t="";
        for(int i=0;i<siz;i++){
            if('A'<=s[i]&&s[i]<='Z'||'a'<=s[i]&&s[i]<='z'||'0'<=s[i]&&s[i]<='9')t+=s[i];
        }
        return t;
    }
    string reverse(string s){
        string t="";
        int siz=s.size();
        for(int i=0;i<siz;i++){
            t=s[i]+t;
        }
        return t;
    }
    int compare(string s, string t){
        int siz=s.size();
        int flag=0;
        for(int i=0;i<siz;i++){
            if(s[i]!=t[i]){
                flag=1;
                break;
            }
        }
        if(flag)return 0;
        else return 1;
    }

    bool isPalindrome(string s) {
        string t=s;
        t=trans(del(t));
        string t1=reverse(t);
        cout<<t<<' '<<t1<<endl;
        if(compare(t,t1))return true;
        else return false;
    }
};
