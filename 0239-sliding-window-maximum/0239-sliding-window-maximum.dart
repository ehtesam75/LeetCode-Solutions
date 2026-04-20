import 'dart:collection';
class Solution {
  List<int> maxSlidingWindow(List<int> nums, int k) {
    int n = nums.length;
    List<int> ans = [];
    var dq = ListQueue<int>();
    for(int i = 0; i < n; i++){
        if(dq.isNotEmpty && dq.first <= (i-k)){
            dq.removeFirst();
        }
        while(dq.isNotEmpty && nums[dq.last] <= nums[i]){
            dq.removeLast();
        }
        dq.add(i);
        if(i+1 >= k){
            ans.add(nums[dq.first]);
        }
    }
    return ans;
  }
}