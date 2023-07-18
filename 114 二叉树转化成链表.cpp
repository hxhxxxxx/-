题目：二叉树转化成链表
解题思路：对二叉树进行先序遍历，然后用额外的空间记录这个结果，之后再改变root即可
这里有一个奇怪的事情，不能对root直接进行改变，只能对左右子树进行改变
class Solution {
public:
    TreeNode* p=new TreeNode(0);
    void preorder(TreeNode* root){
        if(!root)return;
        TreeNode* t=p;
        while(t->right)t=t->right;
        t->right=new TreeNode(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root)return;
        if(!root->left&&!root->right)return;
        preorder(root);
        root->left=nullptr;
        root->right=p->right->right;
    }
};
