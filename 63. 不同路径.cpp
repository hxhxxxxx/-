题目：一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
网格中的障碍物和空位置分别用 1 和 0 来表示。

解题思路：就是简单的看每个点的上跟左，如果是障碍不加，不是障碍，加上路径数

class Solution {
public:
    vector<vector<int>>ans;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int>tmp(n);
        ans.resize(m,tmp);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j])continue;
                else{
                    if(i>0&&j>0){
                        if(!obstacleGrid[i-1][j])ans[i][j]+=ans[i-1][j];
                        if(!obstacleGrid[i][j-1])ans[i][j]+=ans[i][j-1];
                    }else if(i==0&&j>0){
                        if(!obstacleGrid[i][j-1])ans[i][j]+=ans[i][j-1];
                        else ans[i][j]=0;
                    }else if(i>0&&j==0){
                        if(!obstacleGrid[i-1][j])ans[i][j]+=ans[i-1][j];
                        else ans[i][j]=0;
                    }else{
                        ans[i][j]=1;
                    }
                }
                //cout<<i<<' '<<j<<' '<<ans[i][j]<<endl;
            }
        }
        return ans[m-1][n-1];
    }
};

不过上面的代码会比较麻烦，由于没有对两个边界的处理，所以判断语句会比较多，那么可以先对边界进行处理，这样代码会简化很多

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<n;i++)if(obstacleGrid[0][i]!=1){dp[0][i]=1;}else break;
        for(int i=0;i<m;i++)if(obstacleGrid[i][0]!=1){dp[i][0]=1;}else break;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1)dp[i][j]=0;
                else dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
