//Longest Happy Prefix

class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        int j=0;
        int i=j+1;
        vector<int> lps(n,0);

        while(i<n)
        {
            if(s[i]==s[j]){
                lps[i]=j+1;

                j++;
                i++;

            }
            else
            {
                if(j>0)
                j=lps[j-1];
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        return s.substr(0,j);
    }
};