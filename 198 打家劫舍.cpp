题目：你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额
解题思路：也是先写出转移函数，当前的最大值，如果前一个值被使用，那么要判断两种情况的较大值，如果前一个值没有被使用，那么当前值被加入
        而想要做到这点，就需要记录下当前的位置是否被访问过，所以这时候可以用哈希表记录下访问记录
class Solution {
public:
    unordered_map<int,int>m;
    unordered_map<int,int>visit;
    int max(int x,int y){
        if(x>y)return x;
        else return y;
    }
    int rob(vector<int>& nums) {
        int siz=nums.size();
        if(siz==0)return 0;
        if(siz==1)return nums[0];
        if(siz==2)return max(nums[0],nums[1]);
        m[0]=nums[0];
        m[1]=max(nums[0],nums[1]);
        if(m[1]==nums[0]){
            visit[0]=1;
            visit[1]=0;
        }else{
            visit[0]=0;
            visit[1]=1;
        }
        for(int i=2;i<siz;i++){
            if(visit[i-1]){
                m[i]=max(m[i-1],m[i-2]+nums[i]);
                if(m[i]==m[i-1])visit[i]=0;
                else{
                    visit[i-1]=0;
                    visit[i]=1;
                }
            }else{
                m[i]=m[i-1]+nums[i];
                visit[i]=1;
            }
        }
        return m[siz-1];
    }
};
