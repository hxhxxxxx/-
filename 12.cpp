数字转成罗马数字
最笨的方法就是用很多的if else语句，这里也是参考了别人的处理方法，放在两个数组中进行处理会方便一些
class Solution {
public:
    string intToRoman(int num) {
        int a[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res="";
        for(int i=0;i<13;i++){
            while(num>=a[i]){
                num-=a[i];
                res+=s[i];
            }
        }
        return res;
    }
};
