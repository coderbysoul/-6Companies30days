//Maximum Number of Coins You Can Get

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size(),i,sum=0;
        sort(piles.begin(),piles.end());
        int cnt = n/3;
        i = n - 2;
        while(cnt--)
        {
            sum += piles[i];
            i = i - 2;
        }
        return sum;
    }
};