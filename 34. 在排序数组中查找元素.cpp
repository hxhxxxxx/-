题目：
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

解题思路：二分找到目标值，然后再找到前后

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int siz=nums.size();
        if(siz==0)return {-1,-1};
        if(siz==1){
            if(nums[0]==target)return {0,0};
            else return {-1,-1};
        }
        int left=0,right=siz-1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target)break;
            else if(nums[mid]<target)left=mid+1;
            else right=mid-1;
        }
        if(nums[mid]==target){
            int l=mid,r=mid;
            while(l>=0&&nums[l]==target)l--;
            while(r<=siz-1&&nums[r]==target)r++;
            return {l+1,r-1};
        }else return {-1,-1};
    }
};
