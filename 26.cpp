class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int siz;
        siz=nums.size();
        if(siz==0)return 0;
        if(siz==1)return 1;
        int count=1,i=1;
        int tmp=nums[0];
        while(count<siz){
            if(tmp==nums[i])nums.erase(nums.begin()+i);
            else tmp=nums[i++];
            count++;
        }
        return i;
    }
};
