题目： 用数组表示一个数字，然后实现加一操作
解题思路：唯一需要考虑的就是遇到9的时候需要加一，以及在最前面的时候还需要进位的话，需要在数组开头插入一个元素

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        int i=len-1;
        while(digits[i]==9){
            if(i!=0){
                digits[i]=0;
                i--;
            }else{
                digits[i]=0;
                digits.insert(digits.begin(),1);
                return digits;
            }
        }
        digits[i]++;
        return digits;
    }
};
