//https://leetcode.com/problems/next-permutation/description/

//approch 1: using stl
//o(n) time and o(1) space

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};


//approch 2 : w/0 stl
// tc: o(nlogn)
//sc: o(n)

class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        vector<int> v;
        while(i > 0 and nums[i] <= nums[i-1]){
            v.push_back(nums[i]);
            i--;
        }
        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        v.push_back(nums[i]);
        i--;
        v.push_back(nums[i]);
        sort(v.begin(), v.end());

        auto it = upper_bound(v.begin(), v.end(), nums[i]);
        nums[i] = *it;
        v.erase(it);
        int k = 0;
        for(int j = i+1; j < nums.size(); j++){
            nums[j] = v[k++];
        }
    }
};


//approch 3: more polished and optimal
//o(n) time and o(1) space

class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        if(idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n-1; i > idx; i--){
            if(nums[idx] < nums[i]){
                swap(nums[i], nums[idx]);
                break;
            }
        }

        reverse(nums.begin() + idx + 1, nums.end());
    }
};