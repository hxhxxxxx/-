题目：二叉树的层次遍历

解题思路：学了哈希表之后就用哈希表储存层数，其实也可以不用这个方法

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int>tmp;
        vector<vector<int>>ans;
        unordered_map<TreeNode*,int>m;
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        m[root]=1;
        while(!q.empty()){
            TreeNode*t=q.front();
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
                tmp.push_back(t->val);
                ans.push_back(tmp);
                tmp.erase(tmp.begin(),tmp.end());
            }else{
                tmp.push_back(t->val);
            }
        }
        return ans;
    }
};

不用哈希表，就是在每层处理完之后，先计算当前队列中的数量，即为当前的层数，然后在用一个循环，把当前层的元素处理完再跳到别的层去处理即可
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int len;
            len=q.size();
            vector<int>t;
            int i;
            for(i=0;i<len;i++){
              TreeNode* l;
              l=q.front();
              q.pop();
              t.push_back(l->val);
              if(l->left){
                  q.push(l->left);
              }
              if(l->right){
                  q.push(l->right);
              }
            } 
            res.push_back(t);
     }
     return res;
    }
};
