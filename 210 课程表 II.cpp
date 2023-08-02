题目：输出课程表

解题思路：这个就是在前一个版本的基础上，再用一个数组记录一下输出的顺序即可

class Solution {
public:
    vector<vector<int>>edges;
    vector<int>visited;
    vector<int>ans;
    bool flag=true;

    void dfs(int i){
        visited[i]=1;
        for(int v:edges[i]){
            if(visited[v]==0){
                dfs(v);
                if(!flag)return;
            }else if(visited[v]==1){
                flag=false;
                return;
            }
        }
        visited[i]=2;
        ans.insert(ans.begin(),i);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const auto& info: prerequisites){
            edges[info[1]].push_back(info[0]);
        }
        for(int i=0;i<numCourses&&flag;i++){
            if(!visited[i])dfs(i);
        }
        if(!flag)return {};
        return ans;
    }
};
