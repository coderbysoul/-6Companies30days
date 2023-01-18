//Distant Barcodes

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        unordered_map<int,int>m;
        for(auto x:b)m[x]+=1;
        vector<pair<int,int>> a;
        for(auto x:m){
            a.push_back({x.second,x.first});
        }
        sort(a.rbegin(),a.rend());
        
        int i = 0,j = 0,k=0;
        for(auto x:a){
            for(int k=0;k<x.first;++k,++i)b[i]=x.second;
        }
        i=0,j=(b.size()+1)/2;
        vector<int> ab(b.size());
        while(j<b.size()){
            ab[k] = b[i];
            ab[k+1] = b[j];
            i+=1;
            j+=1;
            k+=2;
            
        }
        if( b.size()%2){ab[k] = b[i];}
        return ab;
    }
};