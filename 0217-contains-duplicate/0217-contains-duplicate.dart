class Solution {
  bool containsDuplicate(List<int> nums) {
    Set<int> se = {};
    for(var x in nums){
        if(se.contains(x)){
            return true;
        }
        else se.add(x);
    }
    return false;
  }
}