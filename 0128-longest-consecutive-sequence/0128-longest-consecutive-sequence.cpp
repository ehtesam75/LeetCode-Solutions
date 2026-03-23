class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> se;
        for(auto x : nums){
            se.insert(x);
        }

        int cnt = 1, max_count = INT_MIN, temp;
        for(auto x : se){
            if(se.find(x-1) == se.end()){
                temp = x;
                while(se.find(temp+1) != se.end()){
                    cnt++;
                    temp++;
                }
                max_count = max(max_count, cnt);
                cnt = 1;
            }
        }
        return max(0, max_count);
    }
};