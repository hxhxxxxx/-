题目：给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

解题思路：用中序遍历，找到第k个元素记录下来即可

class Solution {
public:
    int num=0;
    int t;
    void inorder(TreeNode* root,int k){
        if(!root)return;
        inorder(root->left,k);
        num++;
        if(num==k){
            t=root->val;
            return;
        }
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return t;
    }
};
