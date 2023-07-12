题目：以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
解题思路：先排序，之后只要比较后续数组落在哪个区间然后更新区间即可
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int siz=intervals.size();
        if(siz==1)return intervals;
        sort(intervals.begin(),intervals.end());
        vector<int>t=intervals[0];
        vector<vector<int>>ans;
        for(int i=1;i<siz;i++){
            if(t[1]<intervals[i][0]){
                ans.push_back(t);
                t=intervals[i];
            }else if(t[1]<intervals[i][1]){
                t[1]=intervals[i][1];
            }
        }
        ans.push_back(t);
        return ans;
    }
};
