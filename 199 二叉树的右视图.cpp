题目：给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

解题思路：层次遍历二叉树，返回每一层的最右边的节点即可，层次遍历使用队列，而层数可以用哈希表储存，如果与下个节点的层数不同，那么就是该层的最后一个元素

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<TreeNode*,int>m;
        queue<TreeNode*>q;
        vector<int>ans;
        if(!root)return ans;
        q.push(root);
        m[root]=1;
        while(!q.empty()){
            TreeNode* t=q.front();
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
            m[t->left]=m[t]+1;
            m[t->right]=m[t]+1;
            q.pop();
            if(m[t]!=m[q.front()])ans.push_back(t->val);
        }
        return ans;
    }
};
