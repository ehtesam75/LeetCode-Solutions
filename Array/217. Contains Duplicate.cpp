//https://leetcode.com/problems/contains-duplicate/description/

//approch 1: using set
//tc : o (nlogn) 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> se;
        for(auto x : nums){
            se.insert(x);
        }
        return !(se.size() == nums.size());
    }
};


//approch 2: sorting the array
//tc : o(nlogn)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                return 1;
            }
        }
        return 0;
    }
};