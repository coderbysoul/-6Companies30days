//Maximum Sum of an Hourglass

class Solution 
{
public:
    int maxSum(vector<vector<int>>& grid) 
    {
        int maxi = 0;
        int m=grid.size(), n=grid[0].size();
        int sum=0;
        
        for(int i=0; i<=m-3; i++)
        {
            for(int j=0; j<=n-3; j++)
            {
                sum=0;
                for(int c=j; c<j+3; c++) 
                {
                    sum += grid[i][c]; 
                    sum += grid[i+2][c]; 
                }
                sum += grid[i+1][j+1]; 
                maxi = max(maxi, sum); 
            }
        }
        return maxi;
        
    }
};