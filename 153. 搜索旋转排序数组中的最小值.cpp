题目：
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

解题思路：这是33的变换版，更为简单，用同样的思路即可，找到第一个小于第一个值，便是分界线

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int t=nums[0];
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[left]>nums[right]){
            while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]>=t)left=mid+1;
            else right=mid;
        }
        return nums[left];
        }
        return nums[0];
    }
};

