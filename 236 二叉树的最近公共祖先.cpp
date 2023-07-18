题目：二叉树的最近公共祖先
解题思路：从根节点开始，判断它下面是否存在两个要的子节点，如果存在的话，就往下深入，直到停止
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isExist(TreeNode* root,TreeNode* p){
        if(!root)return false;
        if(root->val==p->val)return true;
        return isExist(root->left,p)||isExist(root->right,p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        TreeNode* t=new TreeNode();
        t=root;
        while(isExist(t,p)&&isExist(t,q)){
            if(t->left){
                if(isExist(t->left,p)&&isExist(t->left,q)){
                    t=t->left;
                    continue;
                }
            }
            if(t->right){
                if(isExist(t->right,p)&&isExist(t->right,q)){
                    t=t->right;
                    continue;
                }
            }
            break;
        }
        return t;
    }
};


可以用哈希表来记录父亲节点
先通过深度遍历把每个节点的父亲节点给记录下来
然后先把p的所有祖先节点记录下来
再自下往上走q的祖先节点，如果被访问过说明是最近的公共节点
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>fa;
    unordered_map<TreeNode*,bool>visit;
    void dfs(TreeNode* root){
        if(!root)return;
        if(root->left){
            fa[root->left]=root;
            dfs(root->left);
        }
        if(root->right){
            fa[root->right]=root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root]=NULL;
        dfs(root);
        while(p){
            visit[p]=true;
            p=fa[p];
        }
        while(q){
            if(visit[q])return q;
            q=fa[q];
        }
        return NULL;
    }
};
