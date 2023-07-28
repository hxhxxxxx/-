题目：
根据 百度百科 ， 生命游戏 ，简称为 生命 ，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： 1 即为 活细胞 （live），或 0 即为 死细胞 （dead）。
每个细胞与其八个相邻位置（水平垂直，对角线）的细胞都遵循以下四条生存定律：
如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。

解题思路：先用相同大小的数组储存原先的元素，然后对每个位置进行判断周围活细胞个数，再根据当前状态来判断下一状态

class Solution {
public:
    int count1(vector<vector<int>>& board,int i,int j){
        int m=board.size();
        int n=board[0].size();
        int num1=0;
        if(i==0){
            if(j==0){
                for(int row=i;row<=i+1&&row<m;row++){
                    for(int column=j;column<=j+1&&column<n;column++){
                        if(board[row][column])num1++;
                    }
                }
            }else{
                for(int row=i;row<=i+1&&row<m;row++){
                    for(int column=j-1;column<=j+1&&column<n;column++){
                        if(board[row][column])num1++;
                    }
                }
            }
        }else{
            if(j==0){
                for(int row=i-1;row<=i+1&&row<m;row++){
                    for(int column=j;column<=j+1&&column<n;column++){
                        if(board[row][column])num1++;
                    }
                }
            }else{
                for(int row=i-1;row<=i+1&&row<m;row++){
                    for(int column=j-1;column<=j+1&&column<n;column++){
                        if(board[row][column])num1++;
                    }
                }
            }
        }
        if(board[i][j]==1)return num1-1;
        else return num1;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>tmp;
        for(int i=0;i<m;i++){
            vector<int>t;
            for(int j=0;j<n;j++){
                t.push_back(board[i][j]);
            }
            tmp.push_back(t);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int num=count1(tmp,i,j);
                if(board[i][j]){
                    if(num<2||num>3)board[i][j]=0;
                }else{
                    if(num==3)board[i][j]=1;
                }
            }
        }
        return;
    }
};
