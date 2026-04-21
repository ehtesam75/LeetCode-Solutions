class Solution {
  List<int> findDisappearedNumbers(List<int> nums) {
    int n = nums.length;
    List<int> ans = [];

    //approch 1 : 0(n) time and o(1) space
    // List<bool> arr = List.filled(n+1, false);
    // for(int i = 0; i < n; i++){
    //     arr[nums[i]] = true;
    // }

    // for(int i = 1; i <= n; i++){
    //     if(!arr[i]) ans.add(i);
    // }

    //approch 2: better space
    for(int i = 0; i < n; i++){
        int val = nums[i].abs();
        if(nums[val-1] > 0) nums[val-1] = -nums[val-1];
    }

    for(int i = 0; i < n; i++){
        if(nums[i] > 0) ans.add(i+1);
    }
    return ans;
  }
}