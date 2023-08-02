题目：
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

解题思路：就是判断一下是否存在环，这里借鉴了参考答案，用拓扑排序的方式来找是否存在环

class Solution {
public:
    vector<vector<int>>edges;
    vector<int>visited;
    bool ans=true;

    void dfs(int i){
        visited[i]=1;
        for(int v:edges[i]){
            if(visited[v]==0){
                dfs(v);
                if(!ans)return;
            }else if(visited[v]==1){
                ans=false;
                return;
            }
        }
        visited[i]=2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const auto& info: prerequisites){
            edges[info[1]].push_back(info[0]);
        }
        for(int i=0;i<numCourses&&ans;i++){
            if(!visited[i])dfs(i);
        }
        return ans;
    }
};
