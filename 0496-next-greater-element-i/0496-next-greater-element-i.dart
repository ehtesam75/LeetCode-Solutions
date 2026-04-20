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
    //approch 1: time : o(n * m)
    // List<int> ans = [];
    // for(int i = 0; i < nums1.length; i++){
    //     ans.add(find_grater(nums2, nums1[i]));
    // }
    // return ans;

    //approch 2 : time o(n) using monotonic stack
    List<int> st = [];
    Map<int, int> mp = {};
    for(int i = 0; i < nums2.length; i++){
        while(st.isNotEmpty && st.last < nums2[i]){
            int removed = st.last;
            st.removeLast();
            mp[removed] = nums2[i];
        }
        st.add(nums2[i]);
    }

    List<int> ans = [];
    for(int i = 0; i < nums1.length; i++){
        if(mp.containsKey(nums1[i])){
            ans.add(mp[nums1[i]]!);
        }
        else ans.add(-1);
    }
    return ans;
  }
}