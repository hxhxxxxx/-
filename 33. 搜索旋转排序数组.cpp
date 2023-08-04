题目：
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
  （下标 从 0 开始 计数）。
例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

解题思路：就是先用折半算法找到分界点，然后再在分界点的左右两端根据大小选取分段，然后再在该段里面去找目标

class Solution {
public:
    int mysearch(vector<int>& nums, int target,int l,int r){
        int left=l,right=r;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int t=nums[0];
        if(nums.size()==1){
            if(nums[0]==target)return 0;
            else return -1;
        }
        if(nums[left]>nums[right]){
            while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]>=t)left=mid+1;
            else right=mid;
        }
        if(target<t)return mysearch(nums,target,left,nums.size()-1);
        else return mysearch(nums,target,0,left-1);
        }
        return mysearch(nums,target,0,nums.size()-1);
    }
};
