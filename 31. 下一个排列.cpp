题目：
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。
如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
给你一个整数数组 nums ，找出 nums 的下一个排列。
必须 原地 修改，只允许使用额外常数空间。

解题思路：如果能找到最后两位是升序的，那么直接交换即可，否则就要找一下降序数组然后将其重新排序一个，再找到其中比前一个降序数组前一个数要大的数，交换两者位置即可



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int siz=nums.size();
        int i=1;
        if(siz==1)return;
        int count;
        while(i<siz){
            if(nums[i]<=nums[i-1])count=i;
            i++;
        }
        if(count!=siz-1){
            int t=nums[siz-1];
            nums[siz-1]=nums[siz-2];
            nums[siz-2]=t;
            return;
        }
        i=count;
        while(i>=0){
            if(i==0)break;
            if(nums[i]<=nums[i-1])i--;
            else break;
        }
        sort(nums.begin()+i,nums.end());
        if(i!=0){
            int j=siz-1;
            while(nums[j]>nums[i-1])j--;
            int t=nums[j+1];
            nums[j+1]=nums[i-1];
            nums[i-1]=t;
        }
    }
};

上面代码第一遍遍历是可以优化掉的，因为并不需要，在直接写的时候没有考虑到，做复杂了，在后续分析中可以减掉

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int siz=nums.size();
        int i=1;
        if(siz==1)return;
        int count;
        if(nums[siz-1]>nums[siz-2]){
            int t=nums[siz-1];
            nums[siz-1]=nums[siz-2];
            nums[siz-2]=t;
            return;
        }//直接看最后两个元素的大小
        i=siz-1;
        while(i>=0){
            if(i==0)break;
            if(nums[i]<=nums[i-1])i--;
            else break;
        }//找到降序数组
        sort(nums.begin()+i,nums.end());//重新升序
        if(i!=0){
            int j=siz-1;
            while(nums[j]>nums[i-1])j--;
            int t=nums[j+1];
            nums[j+1]=nums[i-1];
            nums[i-1]=t;
        }//交换第一个大于前面的数即完成要求
    }
};
