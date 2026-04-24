class Solution {
  int subarraySum(List<int> nums, int k) {
    int n = nums.length;
    List<int> prefix = List.filled(n, 0);
    Map<int, int> mp = {};

    prefix[0] = nums[0];
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + nums[i];
    }

    int ans = 0;
    mp[0] = 1;
    for(int i = 0; i < n; i++){
        if(mp.containsKey(prefix[i] - k)){
            ans += mp[prefix[i]-k]!;
        }
        mp[prefix[i]] = (mp[prefix[i]] ?? 0) +1;
    }
    return ans;
  }
}