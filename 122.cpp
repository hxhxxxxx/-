//题目描述：任意买入股票，但不能同时持股
//思路1:用动态规划的思想
//思路2：相当于把日期分为几个不相交的区域，使其差值最大，这里用贪心算法，每个区域都取最大，就可以分到区间为1的区域，取赚钱的即可
//简而言之就是把每个上行的都取到，这里贪心算法的合理性：如果每个小的


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int siz;
        siz=prices.size();
        int profit=0;
        for(int i=0;i<siz-1;i++){
            if(prices[i+1]>prices[i])profit=profit+prices[i+1]-prices[i];
        }
        return profit;
    }
};
