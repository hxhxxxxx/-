题目：给定一个  无重复元素 的 有序 整数数组 nums 。
返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。
列表中的每个区间范围 [a,b] 应该按如下格式输出：
"a->b" ，如果 a != b
"a" ，如果 a == b

解题思路：就简单遍历
  
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int siz=nums.size();
        if(siz==0)return {};
        if(siz==1)return {to_string(nums[0])};
        int pre=0;
        vector<string>ans;
        for(int i=0;i<siz;i++){
            if(i!=siz-1){
                if(nums[i]==nums[i+1]-1)continue;
                else{
                    string t="";
                    if(pre==i){
                        ans.push_back(to_string(nums[pre]));
                        pre=i+1;
                    }else{
                        t=t+to_string(nums[pre])+"->"+to_string(nums[i]);
                        pre=i+1;
                        ans.push_back(t);
                    }
                }
            }else{
                string t="";
                if(pre==i){
                        ans.push_back(to_string(nums[pre]));
                        pre=i+1;
                    }else{
                        t=t+to_string(nums[pre])+"->"+to_string(nums[i]);
                        pre=i+1;
                        ans.push_back(t);
                    }
            }
        }
        return ans;
    }
};
