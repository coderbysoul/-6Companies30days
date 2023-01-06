//Valid Square

class Solution {
public:
    int trailingZeroes(int n) {
       int c=0;
       for(int i=1;pow(5,i)<=n;i++)
       {
           c+=floor(n/pow(5,i));    
       }
       return c;
    }
};