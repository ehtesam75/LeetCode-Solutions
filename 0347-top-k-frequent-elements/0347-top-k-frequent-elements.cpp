static const int N = 2e4 + 7;

class Solution {

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freq(N, 0);
        vector<pair<int, int>> v;
        
        for(int x : nums){
            if(x >= 0) freq[x]++;
            else freq[1e4 + abs(x)]++;
        }

        for(int i = 0; i < N; i++){
            if(freq[i] > 0){
                v.push_back({freq[i], i});
            }
        }

        vector<int> ans;
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        for(int i = 0; i < k; i++){
            if(v[i].second <= 1e4){
                ans.push_back(v[i].second);
            }
            else ans.push_back(-(v[i].second - 1e4));
        }
        return ans;
    }
};