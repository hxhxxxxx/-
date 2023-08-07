题目：给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

解题思路：同样的剪枝回溯，这里由于要判断哪些用过，可以用一个visited数组来记录访问过的值，这样就不会重复

class Solution {
public:
    vector<int>visited;
    void dfs(vector<vector<int>>& ans,vector<int>tmp,vector<int>& nums,int n,int k){
        if(k==n){
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<n;i++){
            if(visited[i])continue;
            tmp.push_back(nums[i]);
            visited[i]=1;
            dfs(ans,tmp,nums,n,k+1);
            tmp.pop_back();
            visited[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int siz=nums.size();
        visited.resize(siz);
        vector<vector<int>>ans;
        vector<int>tmp;
        dfs(ans,tmp,nums,siz,0);
        return ans;
    }
};
