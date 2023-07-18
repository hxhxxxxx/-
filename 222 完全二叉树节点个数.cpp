题目：完全二叉树节点个数
解题思路：最简单的方法就是深度遍历所有的节点
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};
不过该方法没有用到完全二叉树的性质
用一下完全二叉树的性质，如果左右子树层高相同，那么左子树为满树，如果层高不同，那么右子树为满树
class Solution {
public:
    int getheight(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->left;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int lh=getheight(root->left);
        int rh=getheight(root->right);
        if(lh==rh)return (1<<lh)+countNodes(root->right);
        else return countNodes(root->left)+(1<<rh);
    }
};
