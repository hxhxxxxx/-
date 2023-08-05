题目：给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。差值是一个正数，其数值等于两值之差的绝对值。

解题思路：对于一棵树，它的根节点跟左子树最右节点，与右子树最左节点的差值为其最小值，然后再跟左右子树对比

class Solution {
public:
    TreeNode* getright(TreeNode* root){
        if(!root->right)return nullptr;
        TreeNode* t=root->right;
        while(t->left)t=t->left;
        return t;
    }
    TreeNode* getleft(TreeNode* root){
        if(!root->left)return nullptr;
        TreeNode* t=root->left;
        while(t->right)t=t->right;
        return t;
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* l=getleft(root),*r=getright(root);
        int min=100000;
        if(!l&&!r)return 100000;
        if(l){
            int t=root->val-l->val;
            if(min>t)min=t;
        }
        if(r){
            int t=r->val-root->val;
            if(min>t)min=t;
        }
        if(root->left){
            int t=getMinimumDifference(root->left);
            if(min>t)min=t;
        }
        if(root->right){
            int t=getMinimumDifference(root->right);
            if(min>t)min=t;
        }
        return min;
    }
};

不过这个方法比较麻烦，可以用中序遍历，然后就可以按序输出，每次比较相邻两个值的差即可
