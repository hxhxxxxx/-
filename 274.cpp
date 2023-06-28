//h指数 有h篇论文高于h次引用
//这里用一种很笨的方法，就是暴力求解
//可以考虑用空间换时间的方法
class Solution {
public:
    int countnum(vector<int>& citations,int m){
        int siz;
        siz=citations.size();
        int num=0;
        for(int i=0;i<siz;i++){
            if(citations[i]>=m)num++;
        }
        return num;
    }
    int hIndex(vector<int>& citations) {
        int siz;
        siz=citations.size();
        int count=0;
        for(int i=0;i<siz;i++){
            count+=citations[i];
        }
        int avg=count/siz;
        int num=0;
        num=countnum(citations,avg);
        if(num<avg){
            while(num<avg){
            avg--;
            num=countnum(citations,avg);
        }
        }else{
            while(num>avg){
            avg++;
            num=countnum(citations,avg);
            if(avg>num){
                avg--;
                break;
            }
        }
        }
        return avg;
    }
};
