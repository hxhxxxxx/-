题目：在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

解题思路：暴力求解法，去遍历

class Solution {
public:
    int istrue(vector<vector<char>>& matrix,int m,int n,int L){
        for(int i=m;i<m+L;i++){
            for(int j=n;j<n+L;j++){
                if(matrix[i][j]=='0'){
                    return 0;
                }
            }
        }
        return 1;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxL=0;
        int mins=min(m,n);
        for(int L=1;L<=mins;L++){
            for(int i=0;i<=m-L;i++){
                if(maxL==L)continue;
                for(int j=0;j<=n-L;j++){
                    if(maxL==L)continue;
                    if(istrue(matrix,i,j,L)){
                        maxL=L;
                        continue;
                    }
                }
            }
        }
        return maxL*maxL;
    }
};
不过该方法会超时，所以需要找到别的方法

那么借鉴参考答案的思路，用动态规划记录以i,j为右下角的最大正方形的大小
这里跟其左边，上方，与左上方的值有关，为这三者的最小值加一就是当前的值，因为这三个位置的最小值就加上当前点就能够形成一个正方形

class Solution {
public:
    int mymin(int i,int j,int k){
        return min(min(i,j),min(j,k));
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int maxL=0;
        for(int i=0;i<m;i++){
            if(matrix[i][0]=='1'){
                dp[i][0]=1;
                maxL=1;
                }
        }
        for(int i=0;i<n;i++){
            if(matrix[0][i]=='1'){
                dp[0][i]=1;
                maxL=1;
                }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=mymin(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
                    if(dp[i][j]>maxL)maxL=dp[i][j];
                }
            }
        }
        return maxL*maxL;
    }
};




