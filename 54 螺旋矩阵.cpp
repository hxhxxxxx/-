题目：按螺旋的方式遍历矩阵

解题思路：用四个元素记录上下左右的边界，然后依次遍历，其中要注意第一次可以边界重复，第二次不行

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(row==0)return {};
        int column=matrix[0].size();
        if(column==0)return {};
        vector<int>ans;
        int top=0,bottom=row-1,left=0,right=column-1;
        while(left<=right&&top<=bottom){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            for(int i=top+1;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            if(left<right&&top<bottom){
                for(int i=right-1;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            for(int i=bottom-1;i>top;i--){
                ans.push_back(matrix[i][left]);
            }
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        return ans;
    }
};
