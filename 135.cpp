n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

  
  解题思路： 这题的想法是通过一个标记sig来记录分数的变化，是上升下降还是不变
  这样做的原因是只有在一整段变化趋势不变的情况下才会对给的分数有比较大的要求，在这里会有比较大的分数变化，不能仅仅比较相邻的部分
  然后再通过一个count来记录连续的个数，这样来对分数进行更改，并且在改到一个峰值的时候需要与前面的大小进行比较
比如【1，2，3，1】如果不比较就会出现问题
  在书写代码的期间，最开始犯了一个没有对结尾的部分进行处理
  然后就是在对特殊情况比如只有一个的漏掉

class Solution {
public:
    int max(int i,int j){
        if(i>j)return i;
        else return j;
    }
    int signal(vector<int>& ratings,int i){
        if(ratings[i]<ratings[i+1])return 1;
        else if(ratings[i]==ratings[i+1])return 0;
        else return -1;
    }
    int candy(vector<int>& ratings) {
        int siz;
        siz=ratings.size();
        if(siz==1)return 1;
        vector<int>count(siz,1);
        int sig=signal(ratings,0);
        int cnt=0;
        for(int i=1;i<siz-1;){
            int sig1;
            sig1=signal(ratings,i);//得到此处的标记
            if(sig==sig1){
                cnt++;
                i++;
                continue;
            }//如果标记相同，记录个数
            //如果标记不同，那么需要处理
            if(sig==1){
                int j=i-cnt;
                while(j<=i){
                    count[j]=count[j-1]+1;
                    j++;
                }
            }else if(sig==-1){
                int j=i-1;
                while(j>=(i-cnt-1)){
                    if(j==(i-cnt-1))count[j]=max(count[j],count[j+1]+1);
                    else count[j]=count[j+1]+1;
                    j--;
                }
            }
            i=i+1;
            cnt=0;
            sig=sig1;
        }
        if(ratings[0]>ratings[1])count[0]=count[1]+1;
        int i=siz-1;
        if(sig==1){
                int j=i-cnt;
                while(j<=i){
                    count[j]=count[j-1]+1;
                    j++;
                }
            }else if(sig==-1){
                int j=i-1;
                while(j>=(i-cnt-1)){
                    if(j==(i-cnt-1))count[j]=max(count[j],count[j+1]+1);
                    else count[j]=count[j+1]+1;
                    j--;
                }
            }
        int num=0;
        for(int i=0;i<siz;i++)num+=count[i];
        return num;
    }
};
