题目：判断两棵树是否完全相同
解题思路：都是自上而下的递归，21年跟23年的方法
21年：直接对每种情况进行判断
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
          if(p==nullptr&&q==nullptr)return true;
          if(p==nullptr&&q!=nullptr||p!=nullptr&&q==nullptr)return false;
          if(p->val==q->val){
              if(isSameTree(p->left,q->left)&&
              isSameTree(p->right,q->right))return true;
              else return false;
          }else return false;
    }
};
23年：分为两个步骤，第一个是判断两个树的形状是否相同，第二步是判断节点的值是否相同
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)return true;
        else if(!p||!q)return false;
        if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};
