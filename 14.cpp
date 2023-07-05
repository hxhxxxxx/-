题目：最长公共前缀
用了很简单的方法，就用第一个开始遍历，不同就停下
不过在对字符串切割的时候忘记有什么函数，就写了个切割函数


class Solution {
public:
    string getvalue(string& str,int i){
        if(i==0)return "";
        string s="";
        for(int j=0;j<i;j++){
            s+=str[j];
        }
        return s;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int siz=strs.size();
        int len=strs[0].size();
        int i;
        for(i=0;i<len;i++){
            char t=strs[0][i];
            int flag=0;
            for(int j=1;j<siz;j++){
                if(i>strs[j].size()){
                    flag=1;
                    break;
                }
                if(strs[j][i]!=t){
                    flag=1;
                    break;
                }
            }
            if(flag==1)break;
        }
        return getvalue(strs[0],i);
    }
};
