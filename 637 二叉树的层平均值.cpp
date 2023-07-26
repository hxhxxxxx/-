题目：给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。、

解题思路：跟之前一样，层次遍历，用哈希表储存层数，不同的话，计算层平均值

class Solution {
public:
    unordered_map<TreeNode*,int>m;
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        m[root]=0;
        double sum=0.0;
        int cnt=0;
        if(!root->left&&!root->right){
            ans.push_back(root->val);
            return ans;
        }
        while(!q.empty()){
            TreeNode* t=new TreeNode();
            t=q.front();
            if(t->left){
                q.push(t->left);
                m[t->left]=m[t]+1;
            }
            if(t->right){
                q.push(t->right);
                m[t->right]=m[t]+1;
            }
            q.pop();
            if(m[t]!=m[q.front()]){
                sum+=t->val;
                cnt++;
                ans.push_back(sum/cnt);
                sum=0;
                cnt=0;
            }else{
                sum+=t->val;
                cnt++;
            }
        }
        return ans;
    }
};
