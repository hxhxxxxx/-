//题目是轮转数组
//原先采用先插入再切割后半部分多的内容
//后来采用翻转数组的方法，这里直接使用啦reverse函数
//注意这里使用的nums.end()取的是最后元素的后一位地址，
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int siz=nums.size();
        while(k>siz)k-=siz;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
