题目：
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

解题思路：用dfs遍历为1的所有块，然后把遍历过的置为0，这样深度遍历的次数就等于存在的岛屿数量

class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        grid[i][j]='0';
        if((i-1)>=0&&grid[i-1][j]=='1')dfs(grid,i-1,j);
        if((j-1)>=0&&grid[i][j-1]=='1')dfs(grid,i,j-1);
        if((i+1)<m&&grid[i+1][j]=='1')dfs(grid,i+1,j);
        if((j+1)<n&&grid[i][j+1]=='1')dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if(!m)return 0;
        int n=grid[0].size();
        if(!n)return 0;
        int num=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    num++;
                }
            }
        }
        return num;
    }
};
