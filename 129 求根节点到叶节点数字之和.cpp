题目：求根节点到叶节点数字之和
解题思路：用深度遍历去求每个结果
class Solution {
public:
    int dfs(TreeNode* root, int presum){
        if(!root)return 0;
        int sum=presum*10+root->val;
        if(!root->left&&!root->right)return sum;
        else return dfs(root->left,sum)+dfs(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};
