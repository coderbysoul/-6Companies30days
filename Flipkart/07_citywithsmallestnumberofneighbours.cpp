//Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
public:
    int INF = 1e4+1;
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {
        vector<vector<int>> dist(n,vector<int>(n,INF));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)if(i==j) dist[i][j]=0;
        }
        for(auto x:edges){
            dist[x[0]][x[1]] = x[2];
            dist[x[1]][x[0]] = x[2];
        }
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        vector<pair<int,int>>a(n);
        for(int i=0;i<n;++i){
            a[i].first = 0;
            a[i].second = i;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(dist[i][j]<=dT){
                    a[i].first += 1;
                }
            }
        }
        sort(a.rbegin(),a.rend(),[](pair<int,int>t1,pair<int,int>t2){
            if(t1.first==t2.first){
                return t1.second<t2.second;
            }
            return t1.first>t2.first;
        });
        return a[0].second;
    }
};