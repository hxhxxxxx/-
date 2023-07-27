题目：就是检查当前的数独是否符合规范

解题思路：最简单的思路就是每个检查，这样就要走三遍数组
        优化的方式就是把遍历一次数组，用三个数组分别记录行，列，块

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int a[9]={0};
        int i;
        for(i=0;i<9;i++){
            a[i]=0;
        }
        int j,k;
        for(j=0;j<9;j++){
            for(k=0;k<9;k++){
                if(board[j][k]=='.')continue;
                int t;
                t=board[j][k]-'1';
                if(a[t]==1)return false;
                else a[t]=1;
            }
            for(i=0;i<9;i++){
            a[i]=0;
        }
        }
        for(k=0;k<9;k++){
            for(j=0;j<9;j++){
                if(board[j][k]=='.')continue;
                int t;
                t=board[j][k]-'1';
                if(a[t]==1)return false;
                else a[t]=1;
            }
            for(i=0;i<9;i++){
            a[i]=0;
        }
        }
        j=0;
        while(j<9){
            int t2;
            t2=j;
            for(k=0;k<9;k=k+3){
                int t1;
                for(t2=j;t2<j+3;t2++){
                    for(t1=k;t1<k+3;t1++){
                        if(board[t2][t1]=='.')continue;
                int t;
                t=board[t2][t1]-'1';
                if(a[t]==1)return false;
                else a[t]=1;
                    }
                }
                 for(i=0;i<9;i++){
            a[i]=0;
        }
            }
            j=j+3;
        }
        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9];
        int column[9][9];
        int subbox[3][3][9];
        memset(row,0,sizeof(row));
        memset(column,0,sizeof(column));
        memset(subbox,0,sizeof(subbox));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char t=board[i][j];
                if(t!='.'){
                    int index=t-'0'-1;//这里减1是因为序号
                    row[i][index]++;
                    column[j][index]++;
                    subbox[i/3][j/3][index]++;
                    if(row[i][index]>1||column[j][index]>1||subbox[i/3][j/3][index]>1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
