题目：判断路径总和是否存在一个特定的值
解题思路：往下走来看是否有存在的可能的值
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        if(root->left==nullptr&&root->right==nullptr){
            if(root->val==targetSum)return true;
            else return false;
        }else if(root->left==nullptr&&root->right!=nullptr){
            if(hasPathSum(root->right,targetSum-root->val))return true;
        }else if(root->left!=nullptr&&root->right==nullptr){
            if(hasPathSum(root->left,targetSum-root->val))return true;
        }else{
            if(hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val))return true;
        }
        return false;
    }
};
