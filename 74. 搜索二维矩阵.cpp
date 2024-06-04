/*题目：
给你一个满足下述两条属性的 m x n 整数矩阵：
每行中的整数从左到右按非递减顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

解题思路：就先找到对应行，然后再在行里面找，优化可以在行里面用二分法来找
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)right=mid-1;
            else left=mid+1;
        }
        return left;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i;
        for(i=0;i<m;i++){
            if(matrix[i][0]>target)break;
        }
        if(i==0&&matrix[0][0]>target)return false;
        if(i==0&&matrix[0][0]==target)return true;
        int j=searchInsert(matrix[i-1],target);
        if(j>=n)return false;
        if(matrix[i-1][j]==target)return true;
        else return false;
    }
};
