题目：给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

解题思路：就是去找，然后注意一下前后的特殊情况的处理即可

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            int siz=intervals.size();
            vector<vector<int>>ans;
            if(siz==0){
                ans.push_back(newInterval);
                return ans;
            }
            vector<int>t={0,0};
            int i=0;
            while(i<siz){
                if(newInterval[0]>intervals[i][1]){
                    t=intervals[i];
                    ans.push_back(t);
                    i++;
                }else break;
            }
            if(i==siz){
                ans.push_back(newInterval);
                return ans;
            }
            if(intervals[i][0]<newInterval[0])t[0]=intervals[i][0];
            else t[0]=newInterval[0];
            while(i<siz){
                if(newInterval[1]<intervals[i][0]){
                    t[1]=newInterval[1];
                    ans.push_back(t);
                    break;
                }else if(newInterval[1]<=intervals[i][1]){
                    t[1]=intervals[i][1];
                    ans.push_back(t);
                    i++;
                    break;
                }else i++;
            }
            if(i==siz){
                if(newInterval[1]>intervals[i-1][1]){
                    t[1]=newInterval[1];
                    ans.push_back(t);
                    return ans;
                }
            }
            while(i<siz){
                t=intervals[i];
                ans.push_back(t);
                i++;
            }
            return ans;
    }
};
