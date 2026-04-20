class Solution {
  List<int> dailyTemperatures(List<int> temperatures) {
    //approch 1 : o(n) time
    // List<(int, int)> st = [];
    // Map<int, int> mp = {};
    // for(int i = 0; i < temperatures.length; i++){
    //     while(st.isNotEmpty && st.last.$1 < temperatures[i]){
    //         int removed = st.last.$2;
    //         st.removeLast();
    //         mp[removed] = i;
    //     }
    //     st.add((temperatures[i], i));
    // }

    // List<int> ans = [];
    // for(int i = 0; i < temperatures.length; i++){
    //     if(mp.containsKey(i)){
    //         ans.add(mp[i]! - i);
    //     }
    //     else ans.add(0);
    // }
    // return ans;


    //approch 2 : o(n) time but more optimized
    List<int> st = [];
    List<int> ans = List.filled(temperatures.length, 0);

    for(int i = 0; i < temperatures.length; i++){
        while(st.isNotEmpty && temperatures[st.last] < temperatures[i]){
            int removed = st.removeLast();
            ans[removed] = i - removed;
        }
        st.add(i);
    }
    return ans;
  }
}