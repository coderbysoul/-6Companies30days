//Find the Winner of the Circular Game

class Solution {
public:
    int sol(int n,int k){
         if(n==1) return 0;
         int a= sol(n-1,k);
         return (a+k)%n;
    }
    int findTheWinner(int n, int k) {
        return sol(n,k)+1;   
    }
};