题目：三数之和
思路：先固定一个值，然后再用两数之和的解题方法，针对去除相同的答案，只需要排序之和，把相同的值跳过即可
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int siz=nums.size();
        sort(nums.begin(),nums.end());
        int i,j,k,target;
        vector<vector<int>>ans;
        for(i=0;i<siz-2;i++){
            if(nums[i]>0)break;//当最小值大于0时 和必不可能等于0
            if(i>0&&nums[i]==nums[i-1])continue;//去掉重复的可能值
            target=-nums[i];
            j=i+1,k=siz-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    vector<int>t;
                    t.push_back(nums[i]);
                    t.push_back(nums[j]);
                    t.push_back(nums[k]);
                    ans.push_back(t);
                    while(j<k&&nums[j]==nums[++j]);
                    while(j<k&&nums[k]==nums[--k]);
                }else if(nums[j]+nums[k]>target){
                    while(j<k&&nums[k]==nums[--k]);
                }else{
                    while(j<k&&nums[j]==nums[++j]);
                }
            }
        }
        return ans;
    }
};
