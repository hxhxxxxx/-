题目描述：
在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。


解题思路
拿到这题的想法是可以先将两个数组相减得到一个新数组，题目转化为从哪个点出发可以使得后续相加每一步的值不小于0；
//下面这个方法是可以的，但是会超出时间限制，所以需要改进
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int siz;
        siz=gas.size();
        vector<int>t(siz);
        for(int i=0;i<siz;i++)t[i]=gas[i]-cost[i];
        if(siz==1&&t[0]<0)return -1;
        for(int i=0;i<siz;i++){
            int count=1,j=(i+1)%siz;
            int tmp=t[i];
            while(count<siz){
                if(tmp<0)break;
                if(j==i)break;
                tmp+=t[j];
                if(tmp<0)break;
                j=(j+1)%siz;
            }
            if(j==i)return i;
        }
        return -1;
    }
};

//所以来思考有没有什么简便的方法，如果走到一个站无法前进，那么从中间任何一站出发到此站都无法，因为之前可以走的话油箱的油可能更多
//所以按照这个思路来运行的话，可以简化成从头开始跑，但是到哪站停了之后就从哪站开始再跑，而不需要每一个都跑一次，这样就可以把时间复杂度降低到O(n).
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int siz;
        siz=gas.size();
        vector<int>t(siz);
        for(int i=0;i<siz;i++)t[i]=gas[i]-cost[i];
        for(int i=0;i<siz;){
            int tmp=t[i];
            if(tmp<0){
                i++;
                continue;
            }
            int j=(i+1)%siz;
            while(j!=i){
                tmp+=t[j];
                if(tmp<0)break;//j到不了
                j=(j+1)%siz;
            }
            if(j==i)return i;
            else if(j>i)i=j;
            else return -1;
        }      
        return -1;
    }
};
/不过这样会占有额外很多的空间 所以不需要额外创建数组来储存差值 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int siz;
        siz=gas.size();
        for(int i=0;i<siz;){
            int tmp=gas[i]-cost[i];
            if(tmp<0){
                i++;
                continue;
            }
            int j=(i+1)%siz;
            while(j!=i){
                tmp+=gas[j]-cost[j];
                if(tmp<0)break;//j到不了
                j=(j+1)%siz;
            }
            if(j==i)return i;
            else if(j>i)i=j;
            else return -1;
        }      
        return -1;
    }
};
