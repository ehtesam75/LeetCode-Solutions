//approch 1: time complexity O(n)   //n = nums.size()

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        bool present = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == target) present = 1;
        }

        if(present == 0){
            return {-1, -1};
        }

        if(n == 1) return {0, 0};

        vector<int> ans;
        auto it = lower_bound(nums.begin(), nums.end(), target);
        ans.push_back(it - nums.begin());

        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        ans.push_back(it2 - nums.begin() - 1);

        return ans;
    }
};


//approch 2 : time complexity O(log(n))

class Solution {
    int bs(vector<int>& nums, int target, bool is_left_search){
        int l = 0, r = nums.size()-1;
        int index = -1;
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(nums[mid] > target){
                r = mid - 1;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                index = mid;
                if(is_left_search){
                    r = mid - 1;
                }
                else l = mid + 1;
            }
        }
        return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = bs(nums, target, 1);
        int right = bs(nums, target, 0);
        return {left, right};
    }
};

//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/