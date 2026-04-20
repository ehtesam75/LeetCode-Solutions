class Solution {
  List<int> nextGreaterElements(List<int> nums) {
    List<int> st = [];
    List<int> arr = [];
    arr.addAll(nums);
    arr.addAll(nums);

    List<int> ans = List.filled(nums.length, -1);
    for(int i = 0; i < arr.length; i++){
        while(st.isNotEmpty && arr[st.last] < arr[i]){
            int removed = st.last;
            st.removeLast();
            if(removed < nums.length) ans[removed] = arr[i];
        }
        st.add(i);
    }

    return ans;
  }
}