class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> se;
        for(auto x : nums){
            if(se.find(x) != se.end()){
                return 1;
            }
            else se.insert(x);
        }
        return 0;
    }
};