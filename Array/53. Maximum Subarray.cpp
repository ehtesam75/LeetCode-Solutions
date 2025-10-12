// https://leetcode.com/problems/maximum-subarray/

//approch 1: brute force approch
//time com: o(n^3)
//this will give TLE

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //will give tle; o(n^3)
        int n = nums.size();
        long long int ans = nums[0];
        for(int l = 0; l < n; l++){
            for(int r = l; r < n; r++){
                long long sum = 0;
                for(int i = l; i <= r; i++){
                    sum += nums[i];
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};


//approch 2 : further improved
//time : o(n ^ 2)
//this will also give TLE

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //will give tle; o(n^3)
        int n = nums.size();
        long long int ans = nums[0];
        for(int l = 0; l < n; l++){
            long long sum = 0;
            for(int r = l; r < n; r++){
                sum += nums[r];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};



//approch 3: using kandes algorithm
//time comp: o(n)
//most optimized approch

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long int ans = nums[0];
        long long int max_subarray = nums[0];
        for(int i = 1; i < n ; i++){
            max_subarray = max(1ll * nums[i], nums[i] + max_subarray);
            ans = max(ans, max_subarray);
        }
        return ans;
    }
};
