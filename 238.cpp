给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请不要使用除法，且在 O(n) 时间复杂度内完成此题。

拿到这题的最初思路是得到全部的乘积再除，但是这个被题目否定了
而一般对时间有要求的题目，都可以考虑用空间换时间，再加上题目中提到前缀跟后缀，那么就考虑是不是跟前后缀有关系
如果用两个数组来储存前后缀的大小，这样一次遍历就可以得到各个位置前后缀的大小，然后再来一次遍历把前后缀相乘就可以得到除本身外的乘积


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int siz;
        siz=nums.size();
        int first,last;
        vector<int>fw(siz,0);
        vector<int>bw(siz,0);
        vector<int>es;
        fw[0]=1;
        bw[siz-1]=1;
        for(int i=1;i<siz;i++){
            fw[i]=fw[i-1]*nums[i-1];
        }
        for(int j=siz-2;j>=0;j--){
            bw[j]=bw[j+1]*nums[j+1];
        }
        int i=0;
        while(i<siz){
            es.push_back(fw[i]*bw[i]);
            i++;
        }
        return es;
    }
};

//小优化一下，少一次遍历，之前出错出在while循环时忘记i+1了

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int siz;
        siz=nums.size();
        int first,last;
        vector<int>fw(siz,0);
        vector<int>bw(siz,0);
        vector<int>es;
        fw[0]=1;
        bw[siz-1]=1;
        int i=1;
        first=1,last=siz-2;
        while(i<siz){
            fw[first]=fw[first-1]*nums[first-1];
            bw[last]=bw[last+1]*nums[last+1];
            first++,last--,i++;
        }
        i=0;
        while(i<siz){
            es.push_back(fw[i]*bw[i]);
            i++;
        }
        return es;
    }
};
