题目：给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
解题思路：先排序，然后再对序列进行判断即可，不过排序算法可能到不了O（n）的复杂度
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=1;
        int max=1;
        int siz=nums.size();
        if(siz==0)return 0;
        if(siz==1)return 1;
        for(int i=1;i<siz;i++){
          //若序列为连续的，把计数加一
            if(nums[i]==nums[i-1]+1){
                cnt++;
                continue;
            }
          //若相同，那么跳过
            if(nums[i]==nums[i-1])continue;
          //若不是上面的情况，更新计数以及连续最大值
            if(cnt>max)max=cnt;
            cnt=1;
        }
        if(cnt>max)max=cnt;
        return max;
    }
};

不过该题放在哈希表中，思考一下如何运用到哈希表
有一个思路
在遍历数组的时候，去哈希表中寻找有没有该数小1 的数字，如果有，那么把它放入哈希表中，并且它的value为上一个的value加1，并且比较与最大值
不过这个思路在实践中发现也需要先排序才可以
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>m;
        int siz=nums.size();
        if(siz==0)return 0;
        if(siz==1)return 1;
        int max=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<siz;i++){
            if(m.count(nums[i]))continue;
            if(m.count(nums[i]-1)){
                m[nums[i]]=m[nums[i]-1]+1;
                if(m[nums[i]]>max)max=m[nums[i]];
            }else m[nums[i]]=1;
        }
        return max;
    }
};
看了一下参考答案
它的思路是先去掉重复元素，重新搞一个哈希表
然后对表中的每一个元素，先判断它是否有前一个元素，如果存在的话就跳过，因为已经在别的判断中做过了
如果前一个数没出现过，那么去找它的后续连续数字有几个，然后更新最大连续个数
还是非常巧妙的
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set;
        int siz=nums.size();
        for(int i=0;i<siz;i++)set.insert(nums[i]);
        int max=0;
        for(const int& num:set){
            if(!set.count(num-1)){
                int cnum=num;
                int clen=1;
                while(set.count(cnum+1)){
                    clen++;
                    cnum++;
                }
                if(clen>max)max=clen;
            }
        }
        return max;
    }
};
