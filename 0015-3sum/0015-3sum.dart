class Solution {
  List<List<int>> threeSum(List<int> nums) {
    nums.sort();
    int n = nums.length;
    List<List<int>> ans = [];

    for(var i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;

        var fix = nums[i];
        int left = i+1;
        int right = n-1;

        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == -fix){
                ans.add([fix, nums[left], nums[right]]);
                int c_l = nums[left]; int c_r = nums[right];
                left++; right--;
                while(left < right && c_l == nums[left]){
                    left++;
                }
                while(left < right && c_r == nums[right]){
                    right--;
                }
            }
            else if(sum > -fix) right--;
            else left++;
        }
    }
    return ans;
  }
}