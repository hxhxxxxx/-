题目：最大雨水
解题思路：贪心算法
从两侧开始往中间移动，移动规则是移动短板
不过要证实这种移动不会漏掉某些情况
设当前两板的位置分别为i,j
若i为短板，那么移动 i=i+1;
这样移动会漏掉(i,j-1)一直到（i,i+1)的所有情况
但是由于i是短板，所以这些情况中，短板只会更短，并且宽度也是随之降低的，故而不会影响最大值
这就证实了贪心算法的正确性

class Solution {
public:
    int maxArea(vector<int>& height) {
        int h=height.size();
        int i=0,j=h-1;
        int max=0;
        while(i<j){
            if(height[i]<height[j]){
                int t=height[i]*(j-i);
                if(t>max)max=t;
                i++;
            }else{
                int t=height[j]*(j-i);
                if(t>max)max=t;
                j--;
            }
        }
        return max;
    }
};
