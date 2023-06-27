//只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//拿到这道题的最初想法是动态规划，创建数组a[n]，记录着第n天的时候的最优解，当多一天的时候，来递推。
//当找到可以售卖的日期后，开始动态规划
//首先如果当前价格低于原先最低，那么把它记录下来
//对于其他的情况，都把它跟最低的价格日期比较，把其利润跟之前的最高利润比较，如果更高，那么对利润以及相关变量进行更新
//综上所述，一共有几个变量salelow,salehigh,lowest，today，profit
//具体详见下面代码


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int salelow,salehigh,profit,lowest;
        int siz;
        siz=prices.size();
        int i=1;
        salelow=lowest=prices[0];
        profit=0;
    //这里先是找到一个买入卖出的日期，后续的动态规划在其基础上进行操作，前面的if语句来找到第一个可以作为售卖的日期
        while(i<siz){
            if(prices[i]<salelow){
                salelow=lowest=prices[i++];
            }else{
                salehigh=prices[i++];
                profit=salehigh-salelow;
                break;
            }
        }
      //当找到可以售卖的日期后，开始动态规划
      //首先如果当前价格低于原先最低，那么把它记录下来
      //对于其他的情况，都把它跟最低的价格日期比较，把其利润跟之前的最高利润比较，如果更高，那么对利润以及相关变量进行更新
        while(i<siz){
            if(prices[i]<lowest){
                lowest=prices[i++];
            }else{
                int tmp=prices[i]-lowest;
                if(tmp>profit){
                    profit=tmp;
                    salehigh=i;
                    salelow=lowest;
                }
                i++;
            }
        }
        return profit;
    }
};
