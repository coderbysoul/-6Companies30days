//Minimum Consecutive Cards to Pick Up

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        unordered_map <int, int> lastIndex;
        int ans=INT_MAX;
        int flag=0;
        for(int i=0;i<n;i++){
            if(lastIndex.count(cards[i])){
                ans=min(ans,i-lastIndex[cards[i]]+1);
                 flag=1;
            }
            lastIndex[cards[i]]=i;
        }
      return (flag==0?-1:ans);
    }
};