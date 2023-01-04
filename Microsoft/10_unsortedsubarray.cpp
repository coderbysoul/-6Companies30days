//Shortest Unsorted continuous Subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> temp;
        temp = nums;
        sort(temp.begin(),temp.end());
        int n = nums.size();
        
        int i,j;
        for( i=0;i<n;i++)
        {
            if(nums[i]!=temp[i])
                break;
        }
        
        for( j=n-1;j>=0;j--)
        {
            if(nums[j]!=temp[j])
                break;
        }
        int c=0;
        
        for(int k=i;k<=j;k++)
            c++;
        return c;
    }
};