题目：
在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

解题思路：
原来想过深度遍历，但是对于这个问题是行不通的，因为所有腐烂橘子是同时行动的，如果深度遍历就会出问题，深度遍历适合一个点出发
所以需要才用广度遍历，先遍历一次图，把图中所有腐烂的点用队列记录下来，因为下一次就是由它们发散开来，然后也记录新鲜橘子，这里为了判断后面会不会有橘子不会被腐烂
然后用去发散腐烂，朝着四个方向，需要注意边界判断，是否是新鲜橘子，是否已经腐烂过了，这里用dis数组来记录腐烂的时间
最后只要判断有无新鲜橘子，返回正确值即可

class Solution {
public:
    int cnt;
    int dis[10][10];
    int dir_x[4]={0,1,0,-1};
    int dir_y[4]={1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>Q;
        memset(dis,-1,sizeof(dis));
        cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    dis[i][j]=0;
                    Q.push(make_pair(i,j));
                }else if(grid[i][j]==1)cnt++;
            }
        }
        while(!Q.empty()){
            pair<int,int>t=Q.front();
            Q.pop();
            for(int i=0;i<4;i++){
                int tx=t.first+dir_x[i];
                int ty=t.second+dir_y[i];
                if(tx<0||ty<0||tx>=m||ty>=n||!grid[tx][ty]||dis[tx][ty]!=-1)continue;
                dis[tx][ty]=dis[t.first][t.second]+1;
                Q.push(make_pair(tx,ty));
                if(grid[tx][ty]==1){
                    cnt--;
                    ans=dis[tx][ty];
                    if(!cnt)break;
                }
            }
        }
        return cnt?-1:ans;
    }
};
