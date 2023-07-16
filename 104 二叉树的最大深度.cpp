题目：二叉树的最深深度
解题思路：直接用迭代即可
class Solution {
public:
    int max(int x,int y){
        if(x>y)return x;
        else return y;
    }
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
