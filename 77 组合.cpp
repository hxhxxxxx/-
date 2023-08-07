题目：给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。 你可以按 任何顺序 返回答案。

解题思路：就用剪枝回溯的方法即可

class Solution {
public:
    void dfs(vector<vector<int>>& ans,vector<int>& tmp,int n,int t,int k){
        if(k==0){
            ans.push_back(tmp);
            return;
        }
        for(int i=t+1;i<=n;i++){
            tmp.push_back(i);
            dfs(ans,tmp,n,i,k-1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>tmp;
        dfs(ans,tmp,n,0,k);
        return ans;
    }
};
