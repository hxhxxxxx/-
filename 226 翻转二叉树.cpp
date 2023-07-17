题目：翻转整棵二叉树
解题思路：对每棵树，把它的左右子树翻转，然后再交换左右子树即可，然后再加上一个终止条件，主要就是考察如何构造递归

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return nullptr;
        TreeNode* p=new TreeNode();
        p=invertTree(root->left);
        root->left=invertTree(root->right);
        root->right=p;
        return root;
    }
};
