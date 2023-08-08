题目：
给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
请你计算该表达式。返回一个表示表达式值的整数。
注意：
有效的算符为 '+'、'-'、'*' 和 '/' 。
每个操作数（运算对象）都可以是一个整数或者另一个表达式。
两个整数之间的除法总是 向零截断 。
表达式中不含除零运算。
输入是一个根据逆波兰表示法表示的算术表达式。
答案及所有中间计算结果可以用 32 位 整数表示。

逆波兰表达式：

逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
逆波兰表达式主要有以下两个优点：

去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中

解题思路：就按照题干的说明就行了，遇到数字入栈，遇到操作符取数进行操作，对数字处理的时候记得处理正负数值

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stk;
        int siz=tokens.size();
        for(int i=0;i<siz;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int n=stk.top();
                stk.pop();
                int m=stk.top();
                stk.pop();
                if(tokens[i]=="*"){
                    stk.push(m*n);
                }else if(tokens[i]=="/"){
                    stk.push(m/n);
                }else if(tokens[i]=="+"){
                    stk.push(m+n);
                }else{
                    stk.push(m-n);
                }
            }else{
                int len=tokens[i].size();
                int t=0;
                if(tokens[i][0]=='-'){
                    for(int j=1;j<len;j++){
                    t=t*10+tokens[i][j]-'0';
                    }
                    t=0-t;
                }else{
                    for(int j=0;j<len;j++){
                    t=t*10+tokens[i][j]-'0';
                    }
                }
                stk.push(t);
            }
        }
        return stk.top();
    }
};
