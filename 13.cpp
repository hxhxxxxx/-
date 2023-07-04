罗马数字的转化
这题的思路还是比较清晰的，正常情况下是大数在前面，如果遇到小树在前面就要减一下，那么这样把每个字母代表的数字加起来即可

class Solution {
public:
    int getvalue(char c){
        switch(c){
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int siz=s.size();
        if(siz==1)return getvalue(s[0]);
        int num=0;
        for(int i=0;i<siz-1;i++){
            if(getvalue(s[i])<getvalue(s[i+1]))num-=getvalue(s[i]);
            else num+=getvalue(s[i]);
        }
        num+=getvalue(s[siz-1]);
        return num;
    }
};
