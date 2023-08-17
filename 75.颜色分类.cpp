题目：给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
必须在不使用库内置的 sort 函数的情况下解决这个问题。

解题思路：遍历两次，第一次把0的元素往前移，第二次把1的元素往前移

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,white;
        int i=0;
        int siz=nums.size();
        if(siz==1)return;
        while(i<siz){
            if(nums[i]==0){
                swap(nums[i],nums[red]);
                red++;
            }
            i++;
        }
        if(red==siz)return;
        i=red;
        white=red;
        while(i<siz){
            if(nums[i]==1){
                swap(nums[i],nums[white]);
                white++;
            }
            i++;
        }
    }
};

还有一种方法，是使用双指针的方式
这里需要注意的是，对于0的情况，可能会把一个1给换出去，所以需要再把换出去的1给换回来
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,white=0;
        int i=0;
        int siz=nums.size();
        if(siz==1)return;
        while(i<siz){
            if(nums[i]==1){
                swap(nums[i],nums[white]);
                white++;
            }else if(nums[i]==0){
                swap(nums[i],nums[red]);
                if(red<white)swap(nums[i],nums[white]);
                red++;
                white++;
            }
            i++;
        }
        
    }
};
