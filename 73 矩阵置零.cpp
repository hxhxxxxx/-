题目：给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

解题思路：就是遍历一下矩阵，标记一下含有0的行与列。然后再遍历一次矩阵，将这些行列置为0即可

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int>row;
        unordered_map<int,int>column;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!matrix[i][j]){
                    row[i]=1;
                    column[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(row.count(i)){
                for(int j=0;j<n;j++)matrix[i][j]=0;
            }
        }
        for(int j=0;j<n;j++){
            if(column.count(j)){
                for(int i=0;i<m;i++)matrix[i][j]=0;
            }
        }
        return;
    }
};
