题目：成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合

解题思路：每次判断的时候，先加做括号，然后再回溯，加右括号，在最开头的地方设置一些条件判断即可

class Solution {
public:
    void dfs(vector<string>& ans,string s,int m,int n,int t){
        //cout<<m<<' '<<n<<endl;
        if(m>t)return;//防止左括号数量超过要求
        if(n>m)return;//防止括号规则不对
        if(n==t){
            ans.push_back(s);
            //cout<<s<<endl;
            return;
        }//括号数量满足即可
        s.push_back('(');
        dfs(ans,s,m+1,n,t);
        s.pop_back();
        s.push_back(')');
        dfs(ans,s,m,n+1,t);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        s.push_back('(');
        dfs(ans,s,1,0,n);
        return ans;
    }
};
