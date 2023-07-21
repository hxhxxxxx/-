题目：给定一个三角形 triangle ，找出自顶向下的最小路径和。
每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
  也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

解题思路：从上往下的话就是只要储存每个位置的最小值即可，每个位置只要比较上方的两个即可

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp;
        int height=triangle.size();
        if(height==1)return triangle[0][0];
        vector<int>t;
        t.push_back(triangle[0][0]);
        dp.push_back(t);
        for(int i=1;i<height;i++){
            vector<int>tmp;
            tmp.push_back(dp[i-1][0]+triangle[i][0]);
            for(int j=1;j<i;j++){
                if(dp[i-1][j-1]<dp[i-1][j])tmp.push_back(dp[i-1][j-1]+triangle[i][j]);
                else tmp.push_back(dp[i-1][j]+triangle[i][j]);
            }
            tmp.push_back(dp[i-1][i-1]+triangle[i][i]);
            dp.push_back(tmp);
        }
        int min=dp[height-1][0];
        for(int i=1;i<height;i++){
            if(min>dp[height-1][i])min=dp[height-1][i];
        }
        return min;
    }
};
第一次由于是想着动态规划，所以额外搞了一个dp数组，但是实际上并不需要额外的空间来储存

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height=triangle.size();
        if(height==1)return triangle[0][0];
        for(int i=1;i<height;i++){
            triangle[i][0]+=triangle[i-1][0];
            for(int j=1;j<i;j++){
                if(triangle[i-1][j-1]<triangle[i-1][j])triangle[i][j]+=triangle[i-1][j-1];
                else triangle[i][j]+=triangle[i-1][j];
            }
            triangle[i][i]+=triangle[i-1][i-1];
        }
        int min=triangle[height-1][0];
        for(int i=1;i<height;i++){
            if(min>triangle[height-1][i])min=triangle[height-1][i];
        }
        return min;
    }
};
这样处理的话需要每次对第一个跟最后一个额外处理，而且最后还要处理最后一层找到最小的
那么如果从下方开始就不会有上面所说的处理，而且到顶上就是最小值
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        if(row==1)return triangle[0][0];
        else{
          for(int i=row-2;i>=0;i--){
              for(int j=i;j>=0;j--){
                  triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
              }
        }  
        }
        return triangle[0][0];
    }
};
