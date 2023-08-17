题目：给你一棵二叉树的根节点，返回该树的 直径 。
     二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
     两节点之间路径的 长度 由它们之间边数表示。

解题思路：一条路径肯定有它的最高点，也就是只要对每个点让它左右子树的深度相加，即为当前点为最高点的路径的最长长度，然后再取最长即可

class Solution {
public:
    int getdep(TreeNode* root){
        if(!root)return 0;
        return max(getdep(root->left),getdep(root->right))+1;
    }
    int m=0;
    void getpra(TreeNode* root){
        if(!root)return;
        int t=getdep(root->left)+getdep(root->right);
        if(t>m)m=t;
        getpra(root->left);
        getpra(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getpra(root);
        return m;
    }
};
