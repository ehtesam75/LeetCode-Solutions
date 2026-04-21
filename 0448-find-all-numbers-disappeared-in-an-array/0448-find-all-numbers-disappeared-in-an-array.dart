class Solution {
  List<int> findDisappearedNumbers(List<int> nums) {
    int n = nums.length;

    //approch 1 : 0(n) time and o(1) space
    List<bool> arr = List.filled(n+1, false);
    for(int i = 0; i < n; i++){
        arr[nums[i]] = true;
    }

    List<int> ans = [];
    for(int i = 1; i <= n; i++){
        if(!arr[i]) ans.add(i);
    }
    return ans;
  }
}