//Combination Sum with a twist.


class Solution {
    private:
    void helper(int ind,int sum,int k,int n,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(k==0 && sum==n)
        {
            ans.push_back(temp);
            return;
        }
        if(sum>n)
            return;
        for(int i=ind;i<=9;i++){
            if(i>n)
                break;
            temp.push_back(i);
            helper(i+1,sum+i,k-1,n,temp,ans);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>temp;
        vector<vector<int>>ans;
        helper(1,0,k,n,temp,ans);
        return ans;
        
    }
};