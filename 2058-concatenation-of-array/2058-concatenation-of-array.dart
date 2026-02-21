class Solution {
  List<int> getConcatenation(List<int> nums) {
    //dart solution
    List<int> ans = [];
    for(var x in nums){
        ans.add(x);
    }
    for(var x in nums){
        ans.add(x);
    }
    return ans;
  }
}