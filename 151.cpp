反转字符串中的单词

class Solution {
public:
    string getword(string s,int pre,int last){
        string t="";
        for(int i=pre;i<last;i++)t+=s[i];
        return t;
    }
    string reverseWords(string s) {
        string a="";
        int siz=s.size();
        if(siz==1)return s;
        int i=0;
        while(s[i]==' ')i++;
        int pre=i;
        string ans="";
        if(i==siz-1)return ans+s[i];//防止最后一个单词只有一个字符的情况
        for(int j=i+1;j<siz;j++){
            if(s[j]==' '){
                if(ans=="")ans=getword(s,pre,j);
                else ans=getword(s,pre,j)+" "+ans;
                while(s[j]==' ')j++;
                pre=j;
                j--;
            }
        }
        if(s[siz-1]!=' '){
            if(ans=="")return s;
            else return ans=getword(s,pre,siz)+" "+ans;
        }
        return ans;
    }
};
