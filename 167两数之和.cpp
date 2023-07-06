题目：两数之和
解题思路：最简单的方法就是直接暴力遍历
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i,j;
        int siz=numbers.size();
        for(i=0;i<siz-1;i++){
            int flag=0;
            for(j=i+1;j<siz;j++){
                if(numbers[i]+numbers[j]==target){
                    flag=1;
                    break;
                }else if(numbers[i]+numbers[j]>target)break;
            }
            if(flag==1)break;
        }
        vector<int>ans;
        ans.push_back(i+1);
        ans.push_back(j+1);
        return ans;
    }
};
但不幸的是超出了时间限制，所以得换种方式把时间复杂度给降低

解题思路：想用双指针的方法，找到较小值来移动指针，不过这种方法会遗漏掉某些情况，所以不是很合适
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=1;
        int siz=numbers.size();
        while(i<j&&j<=siz-1){
            cout<<i<<' '<<j<<endl;
            if(numbers[i]+numbers[j]==target)break;
            if(j!=siz-1&&j!=i+1){
                if(numbers[i+1]+numbers[j]>=numbers[i]+numbers[j+1])j++;
                else i++;
            }else if(j!=siz-1)j++;
            else if(j!=i+1)i++;
            else break;
        }
        if(i==siz-1)i--;
        if(j==siz)j--;
        vector<int>ans;
        ans.push_back(i+1);
        ans.push_back(j+1);
        return ans;
    }
};

那么重新优化一下第一种方案，不要从头遍历，从中间开始遍历
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i,j;
        int siz=numbers.size();
        for(i=0;i<siz;i++)if(numbers[i]>=target)break;
        for(;i>=0;i--){
            int flag=0;
            for(j=i+1;j<siz;j++){
                if(numbers[i]+numbers[j]==target){
                    flag=1;
                    break;
                }else if(numbers[i]+numbers[j]>target)break;
            }
            if(flag==1)break;
        }
        vector<int>ans;
        ans.push_back(i+1);
        ans.push_back(j+1);
        return ans;
    }
};
