N字形变换

class Solution {
public:
    string convert(string s, int numRows) {
        string t;
        int i,j,siz;
        siz=s.size();
        if(numRows==1){
            i=0;
            while(i<siz){
                t.push_back(s[i++]);
            }
        }else if(numRows==2){
              j=0;
             while(j<siz){
                 t.push_back(s[j]);
                 j=j+2;
             }
             j=1;
             while(j<siz){
                 t.push_back(s[j]);
                 j=j+2;
             }
        }else{
          j=0;
        while(j<siz){
            t.push_back(s[j]);
            j=j+2*(numRows-1);
        }
        for(i=2;i<numRows;i++){
             j=i-1;
            while(j<siz){
                int x;
                x=2*(numRows-i)-1;
                t.push_back(s[j]);
                j=j+x+1;
                if(j<siz)t.push_back(s[j]);
                j=j+2*(i-1);
            }
        }
        j=numRows-1;
        while(j<siz){
            t.push_back(s[j]);
            j=j+2*(numRows-1);
        }
        }
        
        return t;
    }
};
