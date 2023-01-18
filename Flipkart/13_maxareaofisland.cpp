//Max Area of Island


class Solution {
    int sm=0;
public:
    void dfs(int r, int c, vector<vector<int>>& grid, int m, int n){
        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]==0) return ;
        grid[r][c] = 0;
        sm++;
        dfs(r-1, c, grid, m, n);
        dfs(r+1, c, grid, m, n);
        dfs(r, c+1, grid, m, n); 
        dfs(r, c-1, grid, m, n);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int m = grid.size(), n = grid[0].size(), area=0;
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j] == 1){
                   sm=0;
                   dfs(i, j, grid, m, n);
                   area = max(area, sm);
               }
           }
       } 
       return area;
    }
};