int find_grater(List<int> nums, int curr){
    bool found = false;
    for(var i in nums){
        if(found){
            if(i > curr) return i;
        }
        if(i == curr) found = true;
    }
    return -1;
}

class Solution {
  List<int> nextGreaterElement(List<int> nums1, List<int> nums2) {
    //approch 1:
    List<int> ans = [];
    for(int i = 0; i < nums1.length; i++){
        ans.add(find_grater(nums2, nums1[i]));
    }
    return ans;
  }
}