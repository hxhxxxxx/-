

class Solution {
public:
    int min(int i,int j){
        if(i>j)return j;
        else return i;
    }
    int countnum(vector<int>& height,int i,int j){
        int t=min(height[i],height[j]);
        int cnt=0;
        for(int m=i+1;m<j;m++)cnt+=(t-height[m]);
        return cnt;
    }
    int signal(vector<int>& height,int i){
        if(height[i]>height[i+1])return -1;
        else if(height[i]==height[i+1])return 0;
        else return 1;
    }
    int trap(vector<int>& height) {
        int stage;//stage表示阶段，0时表示开始，1时表示下降，2时表示上行
        int siz=height.size();
        if(siz<3)return 0;
        int i=0;
        //先找到第一个坑
        while(signal(height,i)!=-1)i++;
        stage=1;
        //先找到上下行的部分
        int pre=i;
        int num=0;
        while(i<siz-1){
            int sig=signal(height,i);
            if(sig==1){
                if(stage==2)i++;
                else if(stage==1){
                    stage=2;
                    i++;
                }
            }else if(sig==0)i++;
            else{
                if(stage==1)i++;
                else if(stage==2){
                    num+=countnum(height,pre,i);
                    pre=i;
                    stage=1;
                    i++;
                }
            }
        }
        return num;
    }
};
上面这个方法没有考虑到中间可能有的小坑
如果换种思路，从行来考虑
class Solution {
public:
    int max(int i,int j){
        if(i>j)return i;
        else return j;
    }
    int findleft(vector<int>& height,int h){
        int siz=height.size();
        int i=0;
        for(i=0;i<siz;i++){
            if(height[i]>=h)break;
        }
        return i;
    }
    int findright(vector<int>& height,int h){
        int siz=height.size();
        int i;
        for(i=siz-1;i>=0;i--){
            if(height[i]>=h)break;
        }
        return i;
    }
    int countnum(vector<int>& height,int l,int r,int h){
        if(l>=(r-1))return 0;
        int num=0;
        for(int i=l+1;i<r;i++){
            if(height[i]<h)num++;
        }
        return num;
    }
    int trap(vector<int>& height){
        //可以按行考虑，找到某层的最左和最右，然后在找中间空格即可
        int maxh=0;
        int siz=height.size();
        int num=0;
        for(int i=0;i<siz;i++)maxh=max(maxh,height[i]);
        for(int i=0;i<maxh;i++){
            int left=findleft(height,i+1);
            int right=findright(height,i+1);
            num+=countnum(height,left,right,i+1);
        }
        return num;
    }
};
这种方法是可行的，但是超出了时间限制
然后也是参考了别人的做法
用相减的方法
int length = height.size();
        //剪枝，数组长度小于3时不可能接到雨水
        if(length < 3) return 0;
        int l = 0, r = length - 1;

        //定义前一次计算时的高度
        int preHeight = 0;
        //定义雨水 + 陆地的总面积
        int totalArea = 0;
        //定义陆地面积
        int landArea = 0;

        //显然总陆地面积为数组所有数求和
        landArea = accumulate(height.begin(), height.end(), 0);

        while(l < r) {
            //跳过小于等于前一次计算的值
            while(l < r && height[l] <= preHeight) l++;
            while(l < r && height[r] <= preHeight) r--;

            //计算当前高度的面积 = （当前左右指针中较小的值 - 前一次计算的高度）* 宽度
            totalArea += (min(height[l], height[r]) - preHeight) * (r - l + 1);
            //更新前一次的高度
            preHeight = min(height[l], height[r]);
        }

        return totalArea - landArea;

