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


        //approch 2 : o(n) time & o(n) space
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

        
        //approch 3 : o(n) time and o(1) space
        int candidate1 = 0, candidate2 = 0;
        int counter1 = 0, counter2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(counter1 == 0){
                candidate1 = nums[i];
            }
            else if(counter2 == 0){
                candidate2 = nums[i];
            }
            else if(nums[i] == candidate1) counter1++;
            else if(nums[i] == candidate2) counter2++;
            else if(nums[i] != candidate1 and nums[i]  != candidate2){
                counter1--; counter2--;
            }
        }

        int can1_cnt = 0, can2_cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate1) can1_cnt++;
            else if(nums[i] == candidate2) can2_cnt++;
        }

        if(can1_cnt > (n/3)) ans.push_back(can1_cnt);
        if(can2_cnt > (n/3)) ans.push_back(can2_cnt);
        return ans;
    }
};