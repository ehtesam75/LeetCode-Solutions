class Solution {
  int maxArea(List<int> height) {
    int l = 0;
    int r = height.length-1;
    int ans = -1;

    while(l < r){
        ans = max(ans, (r-l).abs() * min(height[l], height[r]));
        // print('$ans ');
        if(height[l] <= height[r]){
            l++;
        }
        else r--;
    }
    return ans;
  }
}