题目：给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        int siz=nums.size();
        while(i<siz&&j<siz){
            while(nums[i]!=0){
                i++;
                if(i==siz)return;
                }
            j=i+1;
            if(j==siz)return;
            while(nums[j]==0){
                j++;
                if(j==siz)return;
            }
            int tmp=nums[i];
            nums[i]=nums[j];
            nums[j]=tmp;
            cout<<i<<' '<<j<<endl;
            i++;
        }
    }
};
该方法有点繁琐，属于是对性质没有完全的吃透，导致多了好多重复的判断，实际上，不用每次让j=i+1,每次只要对j进行判断是否为0，是则前进，不是则放在左边
