题目：给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
解题思路：思路其实是简单的，主要就是要用到哈希表中的一些功能
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        int siz=strs.size();
        for(int i=0;i<siz;i++){
            string key=strs[i];
            sort(key.begin(),key.end());
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto i=mp.begin();i!=mp.end();i++){
            ans.push_back(i->second);
        }
        return ans;
    }
};
