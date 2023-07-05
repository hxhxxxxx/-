题目：最后一个单词的长度
只需要从后往前找到一个非空格，在此基础上再找到第一个空格即可

class Solution {
public:
    int lengthOfLastWord(string s) {
        int siz=s.size();
        int i=siz-1;
        while(i>=0){
            if(s[i]!=' ')break;
            i--;
        }
        int j=i;
        while(j>=0){
            if(s[j]==' ')break;
            j--;
        }
        return i-j;
    }
};
