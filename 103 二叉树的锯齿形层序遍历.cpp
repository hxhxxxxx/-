题目：给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

解题思路：就是在层序遍历的基础上，再对层数进行判断，如果是偶数层，就需要进行头插，以达到倒序的作用
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int row=1;
        while(!q.empty()){
            vector<int>tmp;
            int len=q.size();
            if(row%2==1){
                for(int i=0;i<len;i++){
                    TreeNode* t=q.front();
                    q.pop();
                    if(t->left)q.push(t->left);
                    if(t->right)q.push(t->right);
                    tmp.push_back(t->val);
                }
                ans.push_back(tmp);
            }else{
                for(int i=len;i>0;i--){
                    TreeNode* t=q.front();
                    q.pop();
                    if(t->left)q.push(t->left);
                    if(t->right)q.push(t->right);
                    tmp.insert(tmp.begin(),t->val);
                }
                ans.push_back(tmp);
            }
            row++;
        }
        return ans;
    }
};
