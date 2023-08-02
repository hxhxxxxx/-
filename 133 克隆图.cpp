题目：给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。

解题思路：用深度遍历即可，用两个哈希表分别记录访问记录以及新图与旧图对应点的关系

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,int>visited;
    unordered_map<int,Node*>newmap;
    void dfs(Node* node){
        if(visited.count(node))return;
        visited[node]=1;
        Node* t=new Node(node->val);
        newmap[node->val]=t;
        int num=node->neighbors.size();
        int i=0;
        while(i<num){
            if(newmap.count(node->neighbors[i]->val)){
                Node* tmp=newmap[node->neighbors[i]->val];
                tmp->neighbors.push_back(t);
                t->neighbors.push_back(tmp);
            }
            i++;
        }
        i=0;
        while(i<num){
            dfs(node->neighbors[i]);
            i++;
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        int ans=node->val;
        dfs(node);
        return newmap[ans];
    }
};
