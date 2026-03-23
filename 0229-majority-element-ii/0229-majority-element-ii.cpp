class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        //approch 1 : o(nlogn) time and o(1) space
        // sort(nums.begin(), nums.end());

        // int cnt_cosec = 1;
        // for(int i = 1; i < n; i++){
        //     if(nums[i] == nums[i-1]){
        //         cnt_cosec++;
        //     }
        //     else{
        //         if(cnt_cosec > (n/3)){
        //             ans.push_back(nums[i-1]);
        //         }
        //         cnt_cosec = 1;
        //     }
        // }

        // if(cnt_cosec > (n/3)){
        //     ans.push_back(nums[n-1]);
        // }
        // return ans;


        //approch 2 : o(logn) time & o(n) space
        unordered_map<int, int> mp;
        for(auto x : nums){
            mp[x]++;
        }

        for(auto [u, v] : mp){
            if(v > (n/3)){
                ans.push_back(u);
            }
        }
        return ans;
    }
};