//https://leetcode.com/problems/maximum-matrix-sum/description/

class Solution {
public:
    
         long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        long long sum=0;
        int mino=INT_MAX,neg=0;
         
        for(auto i:matrix)
        {
            for(auto j:i)
            {
                sum+=abs(j); 
                
                if(j<=0)   
                     neg++;  
                
                mino=min(mino,abs(j)); 
            }
        }
        
 
        if(mino==INT_MAX or neg%2==0)  
            return sum;
        
        return sum-2*abs(mino);  
    }
    
};