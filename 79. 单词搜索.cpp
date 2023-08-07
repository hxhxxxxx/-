题目：给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
     单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

解题思路：判断前后左右是否可以前进，不过这里要注意走过的位置不可以重复走，所以这里需要设置一个二维数组visited来判断，否则会重复走原来的路

class Solution {
public:
    bool ans=false;
    void dfs(vector<vector<char>>& board,string word,int t,int m,int x,int y,vector<vector<int>>& visited){
        if(ans)return;
        //cout<<x<<' '<<y<<endl;
        if(m==t){
            ans=true;
            //cout<<1<<endl;
            return;
        }
        if(x>0&&board[x-1][y]==word[t]&&!visited[x-1][y]){
            visited[x-1][y]=1;
            dfs(board,word,t+1,m,x-1,y,visited);
            visited[x-1][y]=0;
        }
        if((x<board.size()-1)&&board[x+1][y]==word[t]&&!visited[x+1][y]){
            visited[x+1][y]=1;
            dfs(board,word,t+1,m,x+1,y,visited);
            visited[x+1][y]=0;
        }
        if(y>0&&board[x][y-1]==word[t]&&!visited[x][y-1]){
            visited[x][y-1]=1;
            dfs(board,word,t+1,m,x,y-1,visited);
            visited[x][y-1]=0;
        }
        if((y<board[0].size()-1)&&board[x][y+1]==word[t]&&!visited[x][y+1]){
            visited[x][y+1]=1;
            dfs(board,word,t+1,m,x,y+1,visited);
            visited[x][y+1]=0;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visited;
        vector<int>tmp(n);
        visited.resize(m,tmp);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans)return ans;
                if(board[i][j]==word[0]){
                    visited[i][j]=1;
                    dfs(board,word,1,word.size(),i,j,visited);
                    visited[i][j]=0;
                }
            }
        }
        return ans;
    }
};
