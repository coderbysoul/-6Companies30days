//Random Pick with Weight

class Solution {
public:
    vector<int> v;

    Solution(vector<int>& w) {
        v.push_back(0);
        for (int i = 0; i < w.size(); ++ i) v.push_back(v.back() + w[i]);
    }
    
    int pickIndex() {
        int num = rand() % v.back();
        auto it = lower_bound(v.begin(), v.end(), num);
        int tmp = distance(v.begin(), it);
        if (*it == num) return tmp;
        return tmp - 1;
    }
};