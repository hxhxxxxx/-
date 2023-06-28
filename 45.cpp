//最小跳，可以建立一个数组，都初始化为n
//首先从第一个开始，a[0]=0,
//然后对后面的可以到达的数组进行判断，把后续的可以到达的位置，把原来记录最少的次数跟a[i]+1比较，如果更小，那么更新，这样即可。

class Solution {
public:

    int jump(vector<int>& nums) {
        int siz;
        siz=nums.size();
        vector<int>a;
        for(int i=0;i<siz;i++){
            a.push_back(siz);
        }
        a[0]=0;
        if(siz==0||siz==1)return 0;
        int i=0;
        while(i<(siz-1)){
            int t=i+1;
            while(t<=(i+nums[i])){
                if(t>(siz-1))break;
                if(a[t]>(a[i]+1))a[t]=a[i]+1;
                t++;
            }
            i++;
        }
        return a[siz-1];
    }
};
