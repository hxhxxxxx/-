题目：给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。
你可以按 任意顺序 返回这些组合。candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
对于给定的输入，保证和为 target 的不同组合数少于 150 个。

解题思路：也是剪枝回溯，这里要点在于为了避免重复，后序加入数组的元素不能在已加入的元素的前面，否则会出现重复的现象

class Solution {
public:
    void dfs(vector<vector<int>>& ans,vector<int>& tmp,int t,int n,vector<int>&candidates,int target){
        if(t>target){
            return;
        }
        if(t==target){
            ans.push_back(tmp);
            return;
        }
        int siz=candidates.size();
        for(int i=n;i<siz;i++){
            tmp.push_back(candidates[i]);
            dfs(ans,tmp,t+candidates[i],i,candidates,target);//在这里用n来记录前面已经入数组的元素的位置
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>tmp;
        dfs(ans,tmp,0,0,candidates,target);
        return ans;
    }
};
