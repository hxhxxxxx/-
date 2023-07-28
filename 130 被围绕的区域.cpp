题目：给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

解题思路：先走一遍，在中间的记为2，在边缘的记为1，第二次遍历，把边缘1的还原成O，第三次遍历，把在中间的2变成X

class Solution {
public:
    void dfs1(vector<vector<char>>& board,int i,int j){
        int m=board.size();
        int n=board[0].size();
        if(i==0||i==m-1||j==0||j==n-1)board[i][j]='1';
        else board[i][j]='2';
        if((i-1)>=0&&board[i-1][j]=='O')dfs1(board,i-1,j);
        if((j-1)>=0&&board[i][j-1]=='O')dfs1(board,i,j-1);
        if((i+1)<m&&board[i+1][j]=='O')dfs1(board,i+1,j);
        if((j+1)<n&&board[i][j+1]=='O')dfs1(board,i,j+1);
    }
    void dfs2(vector<vector<char>>& board,int i,int j){
        int m=board.size();
        int n=board[0].size();
        board[i][j]='O';
        if((i-1)>=0&&(board[i-1][j]=='1'||board[i-1][j]=='2'))dfs2(board,i-1,j);
        if((j-1)>=0&&(board[i][j-1]=='1'||board[i][j-1]=='2'))dfs2(board,i,j-1);
        if((i+1)<m&&(board[i+1][j]=='1'||board[i+1][j]=='2'))dfs2(board,i+1,j);
        if((j+1)<n&&(board[i][j+1]=='1'||board[i][j+1]=='2'))dfs2(board,i,j+1);
    }
    void dfs3(vector<vector<char>>& board,int i,int j){
        int m=board.size();
        int n=board[0].size();
        board[i][j]='X';
        if((i-1)>=0&&board[i-1][j]=='O')dfs3(board,i-1,j);
        if((j-1)>=0&&board[i][j-1]=='O')dfs3(board,i,j-1);
        if((i+1)<m&&board[i+1][j]=='O')dfs3(board,i+1,j);
        if((j+1)<n&&board[i][j+1]=='O')dfs3(board,i,j+1);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')dfs1(board,i,j);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='1')dfs2(board,i,j);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='2')dfs3(board,i,j);
            }
        }
    }
};
