题目：给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。
     如果存在，返回 true ；否则，返回 false 。

解题思路：也是用哈希表，判断是否在哈希表中出现，如果出现，判断位置差距，如果符合就返回正确，如果差距大，那么更新位置
        如果没有出现，那么连同位置一起加入哈希表

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int siz=nums.size();
        for(int i=0;i<siz;i++){
            if(m.count(nums[i])){
                if((i-m[nums[i]])<=k)return true;
                else m[nums[i]]=i;
            }else m[nums[i]]=i;
        }
        return false;
    }
};
