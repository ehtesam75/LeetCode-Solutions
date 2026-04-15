class Solution {
  bool containsNearbyDuplicate(List<int> nums, int k) {
    int n = nums.length;
    //approch 1 : o(n) time and o(n) space
    // Map<int, int> mp = {};

    // for(int i = 0; i < n; i++){
    //     if(mp.containsKey(nums[i])){
    //         int lastPos = mp[nums[i]]!;
    //         if(i-lastPos <= k) return true;
    //     }
    //     mp[nums[i]] = i;
    // }
    // return false;


    //approch 2 :sliding window o(n) time o(1) space

    final window = <int>{};
    for(int i = 0; i < n; i++){
        if(window.contains(nums[i])){
            return true;
        }
        window.add(nums[i]);

        if(window.length > k){
            window.remove(nums[i-k]);
        }
    }
    return false;
  }
}