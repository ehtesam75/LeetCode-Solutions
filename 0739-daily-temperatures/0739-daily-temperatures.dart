class Solution {
  List<int> dailyTemperatures(List<int> temperatures) {
    List<(int, int)> st = [];
    Map<int, int> mp = {};
    for(int i = 0; i < temperatures.length; i++){
        while(st.isNotEmpty && st.last.$1 < temperatures[i]){
            int removed = st.last.$2;
            st.removeLast();
            mp[removed] = i;
        }
        st.add((temperatures[i], i));
    }

    List<int> ans = [];
    for(int i = 0; i < temperatures.length; i++){
        if(mp.containsKey(i)){
            ans.add(mp[i]! - i);
            // print(mp[temperatures[i]]!);
        }
        else ans.add(0);
    }
    return ans;
  }
}