//Number of Ways to Separate Numbers

const int mod=1000000007;

int go(int pos,string &prev,string &num,map<pair<int,string>,int> &dp){
    
    
    if(dp.count(make_pair(pos,prev)))
        return dp[make_pair(pos,prev)];
    
    int prev_size=prev.size();
    int n=num.size();
    
    if(pos>=n)
        return 1;
    
    if(num[pos]=='0')
        return 0;
    
    int ans=0;
    string newString="";
    for(int next_pos=pos;next_pos<n;next_pos++){
            newString+=num[next_pos];
            if(newString.size()<prev_size)
                continue;
             if(newString.size()==prev.size()){
                 if(newString>=prev){
                     ans+=go(next_pos+1,newString,num,dp);
                     ans%=mod;
                 }
             }
        else {
            ans+=go(next_pos+1,newString,num,dp);
            ans%=mod;
        }
    }
    
    return dp[make_pair(pos,prev)]=ans;
}
class Solution {
public:
    int numberOfCombinations(string nums) {
        int n=nums.size();
        int ans=0;
        int dp[n][n+1];
        memset(dp,0,sizeof(dp));
        string prev="";
        
        vector<vector<int>>lcp(n,vector<int>(n,0));

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]==nums[j]){
                    lcp[i][j]=1;
                    if(j+1<n)
                    lcp[i][j]+=lcp[i+1][j+1];
                }
            }
        }
        int pref[n][1+n];
        memset(pref,0,sizeof(pref));
        
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                int len=i-j+1;
                
                if(nums[j]=='0')
                    continue;
                 
               int standing=j-1;
                
                if(standing>=0)
                dp[i][len]+=pref[standing][len-1];
                else 
                    dp[i][len]=1;
                
                dp[i][len]%=mod;
                int where=standing-len+1;
                if(where>=0){
                    if(lcp[where][j]>=len ||  nums[where+lcp[where][j]]<nums[j+lcp[where][j]]){
                        if(standing>=0)
                        {dp[i][len]+=dp[standing][len];
                        dp[i][len]%=mod;}
                    }
                }
                
            }
            
            for(int len=1;len<=n;len++){
                pref[i][len]=dp[i][len];
                pref[i][len]+=pref[i][len-1];
                pref[i][len]%=mod;
            }
        }
        
        return pref[n-1][n];
        

    }
};