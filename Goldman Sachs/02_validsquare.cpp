//Valid Square

class Solution {
    private:
     int calLength(vector<int>& a, vector<int>& b){
         return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
     }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
       int d12 = calLength(p1,p2);
        int d23 = calLength(p2,p3);
        int d34 = calLength(p3,p4);
        int d14 = calLength(p1,p4);
        int d13 = calLength(p1,p3);
        int d24 = calLength(p2,p4);
        

        unordered_set <int> s;
        s.insert({d12, d23, d34, d14, d13, d24});

        return !s.count(0) && s.size() == 2;

        
        
    }
};