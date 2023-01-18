//Closest Prime Numbers in Range

class Solution {
public:
    vector<bool> SieveOfEratosthenes(int n)
    {
        vector<bool> prime(n+1,1);
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        return prime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool >is_prime = SieveOfEratosthenes(right);
        vector<int> a;

        for(int i=left;i<=right;++i){
            if(i==1)continue;
            if(is_prime[i]){
                a.push_back(i);
            }
        }
        if(a.size()<=1)return {-1,-1};
        int x=-1,y=-1;
        for(int i=0;i<a.size()-1;++i){
            if(x==-1){
                x = a[i];
                y = a[i+1];
            }
            else{
                if(y-x>a[i+1]-a[i]){
                    x = a[i];
                    y = a[i+1];
                }
            }
        }
        return {x,y};
    }
};