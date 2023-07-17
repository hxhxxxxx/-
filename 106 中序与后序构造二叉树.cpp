题目：中序与后序构造二叉树
解题思路：同样是分析数组的组成方式，然后拆开分解即可，中序：左子树根右子树 ， 后序： 左子树根右子树
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
    unordered_map<int,int>m;
    TreeNode* buildmytree(vector<int>& inorder, vector<int>& postorder,int il,int ir,int pl,int pr){
        if(il>ir)return nullptr;
        int inroot=m[postorder[pr]];
        int len=inroot-il;
        TreeNode* p=new TreeNode(inorder[inroot]);
        p->left=buildmytree(inorder,postorder,il,inroot-1,pl,pl+len-1);
        p->right=buildmytree(inorder,postorder,inroot+1,ir,pl+len,pr-1);
        return p;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int siz=inorder.size();
        for(int i=0;i<siz;i++){
            m[inorder[i]]=i;
        }
        TreeNode* p=new TreeNode();
        p=buildmytree(inorder,postorder,0,siz-1,0,siz-1);
        return p;
    }
};
