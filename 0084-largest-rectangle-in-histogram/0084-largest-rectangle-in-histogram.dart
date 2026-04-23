class Solution {
  int largestRectangleArea(List<int> heights) {
    int n = heights.length;
    List<int> st = [];
    Map<int, int> after = {};
    for(int i = 0; i < n; i++){
        while(st.isNotEmpty && heights[st.last] > heights[i]){
            int removed = st.removeLast();
            after[removed] = i-1;
        }
        st.add(i);
    }

    while(st.isNotEmpty){
        after[st.last] = n-1;
        st.removeLast();
    }

    Map<int, int> before = {};
    for(int i = n-1; i >= 0; i--){
        while(st.isNotEmpty && heights[st.last] > heights[i]){
            int removed = st.removeLast();
            before[removed] = i+1;
        }
        st.add(i);
    }

    while(st.isNotEmpty){
        before[st.last] = 0;
        st.removeLast();
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        // print(after[i]);
        int areaEach = (after[i]! - before[i]! + 1) * heights[i];
        print('${after[i]} ${before[i]} ${heights[i]} ${areaEach}');
        ans = max(ans, areaEach);
    }
    return ans;
  }
}