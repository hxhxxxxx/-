题目：给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
      有效 二叉搜索树定义如下：
      节点的左子树只包含 小于 当前节点的数。
      节点的右子树只包含 大于 当前节点的数。
      所有左子树和右子树自身必须也是二叉搜索树。

解题思路：最简单的就是自顶而下的递归，这也是21年的做法，不过借鉴了之前的中序遍历的思路，只需要中序遍历来判断相邻的两个值是否符合要求即可，这也是23年版的

23年版的
class Solution {
public:
    bool ans=true;
    int pre;
    bool flag=false;
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        if(flag){
            if(root->val<=pre){
                ans=false;
                return;
            }else{
                pre=root->val;
            }
        }else{
            pre=root->val;
            flag=true;
        }
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};

21年版本的
class Solution {
public:
    bool isValidBST(TreeNode* root) {
          if(root==nullptr)return true;
          TreeNode* p;
          p=root->left;
          if(p!=nullptr){
              while(p->right!=nullptr)p=p->right;
              if(p->val>=root->val)return false;
          }
          p=root->right;
          if(p!=nullptr){
              while(p->left!=nullptr)p=p->left;
              if(p->val<=root->val)return false;
          }
          if(isValidBST(root->left)&&isValidBST(root->right))
          return true;
          else return false;
    }
};

