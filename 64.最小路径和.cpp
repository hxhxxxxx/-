题目：给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

解题思路：设置每个最小值，然后不断扩大即可

class Solution {
public:
    vector<vector<int>>ans;
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>tmp(n);
        ans.resize(m,tmp);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0&&j>0){
                    int t1=grid[i][j]+ans[i-1][j];
                    int t2=grid[i][j]+ans[i][j-1];
                    if(t1>t2)ans[i][j]=t2;
                    else ans[i][j]=t1;
                }else if(i==0&&j>0){
                    ans[i][j]=ans[i][j-1]+grid[i][j];
                }else if(i>0&&j==0){
                    ans[i][j]=ans[i-1][j]+grid[i][j];
                }else{
                    ans[i][j]=grid[i][j];
                }
            }
        }
        return ans[m-1][n-1];
    }
};
