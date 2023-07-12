题目：给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

解题思路：主要是对栈的使用

class Solution {
public:
    bool isValid(string s) {
        int siz=s.size();
        int i=0;
        stack<char>stk;
        while(i<siz){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')stk.push(s[i]);
            else{
                switch(s[i]){
                    case ')':if(stk.empty()||stk.top()!='(')return false;
                            else stk.pop();
                            break;
                    case ']':if(stk.empty()||stk.top()!='[')return false;else stk.pop();break;
                    case '}':if(stk.empty()||stk.top()!='{')return false;else stk.pop();break;
                }
            }
            i++;
        }
        if(!stk.empty())return false;
        else return true;
    }
};
