题目：填充节点下一个右指针
解题思路：也是分为两版23年1月与23年7月
1月版就是分类讨论，比较麻烦
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            if(q.size()==1){
              Node* t=q.front();
            if(t->left!=nullptr&&t->right!=nullptr){
                q.push(t->left);
                q.push(t->right);
            }else if(t->left!=nullptr)q.push(t->left);
            else if(t->right!=nullptr)q.push(t->right);
            q.pop();
            t->next=nullptr;  
            }else{
                //q.size()要提前算好，不然后面会改变
                int s=q.size();
                Node* t=q.front();
                q.pop();
                if(t->left!=nullptr&&t->right!=nullptr){
                q.push(t->left);
                q.push(t->right);
                 }else if(t->left!=nullptr)q.push(t->left);
                 else if(t->right!=nullptr)q.push(t->right);
                for(int i=1;i<s;i++){
                    Node* p=q.front();
                    q.pop();
                    t->next=p;
                    t=p;
                    if(t->left!=nullptr&&t->right!=nullptr){
                       q.push(t->left);
                       q.push(t->right);
                      }else if(t->left!=nullptr)q.push(t->left);
                      else if(t->right!=nullptr)q.push(t->right);
                }
                t->next=nullptr;
            }
        }
        return root;
    }
};

7月版，由于学习了哈希表，对此的使用比较熟练了，就想到可以把单个节点的层数用哈希表记录，然后再用队列，只需要判断当前节点的层数与队列中后一个的层数是否相同即可
如果层数相同，那么就改变next指针，否则不需要改变，由于队列的特性，输出的就是层次遍历
class Solution {
public:
    unordered_map<Node*,int>m;
    Node* connect(Node* root) {
        if(!root)return NULL;
        queue<Node*>q;
        q.push(root);
        m[root]=0;
        while(!q.empty()){
            Node* t=q.front();
            cout<<t->val<<endl;
            if(t->left){
                q.push(t->left);
                m[t->left]=m[t]+1;
            }
            if(t->right){
                q.push(t->right);
                m[t->right]=m[t]+1;
            }
            q.pop();
            if(!q.empty()){
                if(m[t]==m[q.front()])t->next=q.front();
            }
        }
        return root;
    }
};
