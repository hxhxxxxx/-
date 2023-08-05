题目：给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

解题思路：一个标准的剪枝回溯，随着在每个处理完之后需要进行删除

class Solution {
public:
    vector<string>num={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(vector<string>& ans,int index,string digits,string tmp){
        if(index==digits.size()){
            ans.push_back(tmp);
            return;
        }
        int t=digits[index]-'0';
        string s=num[t];
        int siz=s.size();
        for(int i=0;i<siz;i++){
            tmp+=s[i];
            dfs(ans,index+1,digits,tmp);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int siz=digits.size();
        if(siz==0)return ans;
        dfs(ans,0,digits,"");
        return ans;
    }
};
