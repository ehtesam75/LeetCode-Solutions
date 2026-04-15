class Solution {
  bool containsNearbyDuplicate(List<int> nums, int k) {
    int n = nums.length;
    Map<int, int> mp = {};

    for(int i = 0; i < n; i++){
        if(mp.containsKey(nums[i])){
            int lastPos = mp[nums[i]]!;
            if(i-lastPos <= k) return true;
        }
        mp[nums[i]] = i;
    }
    return false;
  }
}