//Sort an Array

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        multiset<int>s;
        vector<int>ans;

        for(int i=0;i<nums.size();i++)
        s.insert(nums[i]);
        for(auto it:s)
        ans.push_back(it);

        return ans;
    }
};