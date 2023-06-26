//题目是找到超过一半的数
//思路是建立一张哈希表，这里有关哈希表的相关知识
//可以参考 https://blog.csdn.net/m0_51233386/article/details/126000760?ops_request_misc=&request_id=&biz_id=102&utm_term=哈希表c++使用&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-126000760.142^v88^control_2,239^v2^insert_chatgpt&spm=1018.2226.3001.4187
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int siz=nums.size();
        unordered_map<int,int>m;
        int i;
        for(i=0;i<siz;i++){
            if(m.find(nums[i])!=m.end())m[nums[i]]++;
            else m[nums[i]]=1;
            if(m[nums[i]]>(siz/2))return nums[i];
        }
        return 0;
    }
};
