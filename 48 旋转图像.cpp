题目：给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
     你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

解题思路：跟螺旋输出矩阵类似，都可以先用定位的方法确定四个角，然后按序交换四个角的值即可

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1)return;
        int top=0,bottom=n-1,left=0,right=n-1;
        while(top<bottom){
            vector<int>tmp;
            for(int i=bottom;i>top;i--){
                tmp.push_back(matrix[i][left]);
            }
            for(int i=0;i<right-left;i++){
                matrix[bottom-i][left]=matrix[bottom][right-i];
                matrix[bottom][right-i]=matrix[top+i][right];
                matrix[top+i][right]=matrix[top][left+i];
                matrix[top][left+i]=tmp[i];
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        return;
    }
};
