//Top K Frequent Words

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(auto const& w : words) freq[w]++;
        
        auto cmp = [&freq](string const& a, string const& b) {
            return freq[a] == freq[b] ? a < b : freq[a] > freq[b];
        };
        priority_queue<string, vector<string>, decltype(cmp)> minheap(cmp);
        for(auto const& [word, count] : freq) {
            minheap.push(word);
            if(minheap.size() > k)
                minheap.pop();
        }

        vector<string> topk;
        for(; !minheap.empty(); minheap.pop())
            topk.push_back(minheap.top());

        return {topk.rbegin(), topk.rend()};
    }
};