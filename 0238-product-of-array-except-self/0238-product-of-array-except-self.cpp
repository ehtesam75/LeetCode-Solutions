class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //approach 1 : time O(n) and space o(n)
        // int n = nums.size();
        // vector<int> prefix(n, 1);
        // vector<int> suffix(n, 1);

        // prefix[0] = nums[0];
        // for(int i = 1; i < n; i++){
        //     prefix[i] = prefix[i-1] * nums[i];
        // }

        // suffix[n-1] = nums[n-1];
        // for(int i = n - 2; i >= 0; i--){
        //     suffix[i] = suffix[i+1] * nums[i];
        // }

        // vector<int> ans(n);
        // int total;
        // for(int i = 0; i < n; i++){
        //     total = 1;
        //     if(i > 0) total *= prefix[i-1];
        //     if(i < n-1) total *= suffix[i+1];
        //     ans[i] = total;
        // }
        // return ans;

        //approach 2:time o(n) and space o(n) (O(1) extra space complexity)
        int n = nums.size();
        vector<int> res(n, 1);

        res[0] = 1;
        for(int i = 1; i < n; i++){
            res[i] = res[i-1] * nums[i-1];
        }

        int suffix = 1;
        for(int i = n-1; i >= 0; i--){
            res[i] *= suffix;
            suffix *= nums[i];
        }
        return res;
    }
};