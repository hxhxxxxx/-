题目：由前序中序构造二叉树
解题思路：根据前序跟中序的特征，可以知道前序的数组：根左子树右子树，而中序的数组是左子树根右子树，这样就可以把两个数组分成三个部分，然后再递归构造即可
class Solution {
public:
    int find(vector<int>&order,int k){
        int siz=order.size();
        int i=0;
        for(i=0;i<siz;i++)if(order[i]==k)break;
        return i;
    }
    TreeNode* buildmytree(vector<int>& preorder, vector<int>& inorder,int pl,int pr,int il,int ir){
        if(pl>=preorder.size()||pr>=preorder.size()||il>=inorder.size()||ir>=inorder.size()||pl>pr||il>ir)return nullptr;
        if(pl==pr){
            TreeNode* p1=new TreeNode(preorder[pl]);
            return p1;
        }
        TreeNode* p=new TreeNode(preorder[pl]);
        int t=find(inorder,preorder[pl]);
        p->left=buildmytree(preorder,inorder,pl+1,pl+t-il,il,t-1);
        p->right=buildmytree(preorder,inorder,pl+1+t-il,pr,t+1,ir);
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int siz=preorder.size();
        TreeNode* p=new TreeNode();
        p=buildmytree(preorder,inorder,0,siz-1,0,siz-1);
        return p;
    }
};

不过对于查找子树中的数字，可以不用单独写函数，可以利用哈希表即可
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
private:
    unordered_map<int, int> index;
public:
    TreeNode* mybuildTree(vector<int>& preorder, vector<int>& inorder,int preleft,int preright,int inleft,int inright){
        if(preleft>preright)return nullptr;
        int pre_root=preleft;
        int in_root=index[preorder[pre_root]];
        int len1=in_root-inleft;
        TreeNode* root=new TreeNode(preorder[pre_root]);
        root->left=mybuildTree(preorder,inorder,pre_root+1,pre_root+len1,inleft,in_root-1);
        root->right=mybuildTree(preorder,inorder,pre_root+len1+1,preright,in_root+1,inright);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            index[inorder[i]]=i;
        }
        return mybuildTree(preorder, inorder,0,n-1,0,n-1);
    }
};
