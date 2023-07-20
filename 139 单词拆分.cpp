题目：单词拆分，给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
解题思路：先把单词放入哈希表中，然后对遍历字符串，从每个位置判断是否可以被字典里的词组成
        不过这里用到了字符串的一些函数
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto worddicset=unordered_set<string>();
        for(auto word: wordDict){
            worddicset.insert(word);
        }
        auto dp=vector<bool>(s.size()+1);
        dp[0]=true;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                    //这里也可以用count函数来判断 if(dp[j]&& worddicset.count(s.substr(j,i-j)))
                if(dp[j]&& worddicset.find(s.substr(j,i-j))!=worddicset.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
