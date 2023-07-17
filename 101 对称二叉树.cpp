题目：判断是否为对称二叉树
解题思路：这题也是分为两版 ，21年与23年
  
21年由于没做前面两题，思路还是比较直接的，就是对树自上而下进行处理，判断左右两边的树一层一层往下走
class Solution {
public:
   bool lrsame(TreeNode* p,TreeNode*q){
        if(p==nullptr&&q==nullptr)return true; 
        if(p==nullptr&&q!=nullptr||
        p!=nullptr&&q==nullptr)return false;
        if(p->val==q->val){
            if(lrsame(p->left,q->right)
            &&lrsame(p->right,q->left))
            return true;
            else return false;
        }else return false;   
   }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
       return lrsame(root->left,root->right);
    }
};

23年版的，由于做了前面两题，翻转二叉树与相同二叉树，所以就有了先把左子树翻转，然后再判断左右子树是否相同，相同则为对称子树
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)return true;
        else if(!p||!q)return false;
        if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return nullptr;
        TreeNode* p=new TreeNode();
        p=invertTree(root->left);
        root->left=invertTree(root->right);
        root->right=p;
        return root;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        TreeNode* p=new TreeNode();
        p=invertTree(root->left);
        return isSameTree(p,root->right);
    }
};
