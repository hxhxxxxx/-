class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int siz;
        siz=nums.size();
        if(siz==0)return 0;
        if(siz==1)return 1;
        int i=1,count=1;
        int tmp=nums[0];//记录当前的值
        int times=1;//记录当前值出现的次数
        while(count<siz){
            if(tmp!=nums[i]){
                tmp=nums[i++];
                times=1;
            }else if(times>1){
                nums.erase(nums.begin()+i);
            }else{
                times++;
                i++;
            }
            count++;
        }
        return i;
    }
};
