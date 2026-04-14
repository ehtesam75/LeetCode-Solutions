class Solution {
  int trap(List<int> height) {
    int n = height.length;
    List<int> rightMax = List.filled(n, 0);
    List<int> leftMax = List.filled(n, 0);

    leftMax[0] = 0;
    leftMax[n-1] = 0;

    int l_max = -1, r_max = -1;
    for(int i = 1; i < n; i++){
        l_max = max(l_max, height[i-1]);
        leftMax[i] = l_max;
    }

    for(int i = n-2; i >= 0; i--){
        r_max = max(r_max, height[i+1]);
        rightMax[i] = r_max;
        print(rightMax[i]);
    }

    int water = 0;
    for(int i = 0; i < n; i++){
        int temp = min(leftMax[i], rightMax[i]) - height[i];
        water += (temp > 0) ? temp : 0;
    }
    return water;
  }
}