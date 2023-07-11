题目：两数之和
思路：除了暴力算法之外，可以用哈希表
就是先把用过的元素放入哈希表中，在后续元素处理中，先到哈希表中找有没有target-nums[i]元素，如果有就返回，如果没有就加入哈希表，键值对为<nums[i],i>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        int siz=nums.size();
        for(int i=0;i<siz;i++){
            auto it=m.find(target-nums[i]);
            if(it!=m.end())return {it->second,i};//找得到该元素   
            m[nums[i]]=i;
        }
        return {};
    }
};
