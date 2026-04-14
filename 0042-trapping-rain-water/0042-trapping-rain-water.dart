class Solution {
  int trap(List<int> height) {
    int n = height.length;

    //approch 1 : using pre computed array; o(n) time and o(n) space
    // List<int> rightMax = List.filled(n, 0);
    // List<int> leftMax = List.filled(n, 0);

    // leftMax[0] = 0;
    // leftMax[n-1] = 0;

    // int l_max = -1, r_max = -1;
    // for(int i = 1; i < n; i++){
    //     l_max = max(l_max, height[i-1]);
    //     leftMax[i] = l_max;
    // }

    // for(int i = n-2; i >= 0; i--){
    //     r_max = max(r_max, height[i+1]);
    //     rightMax[i] = r_max;
    //     print(rightMax[i]);
    // }

    // int water = 0;
    // for(int i = 0; i < n; i++){
    //     int temp = min(leftMax[i], rightMax[i]) - height[i];
    //     water += (temp > 0) ? temp : 0;
    // }
    // return water;


    //approch 2 : two pointer ; o(n) time and o(1) space
    int start = 0, end = n-1;
    int leftMax = -1, rightMax = -1;
    int water = 0;

    while(start < end){
        leftMax = max(leftMax, height[start]);
        rightMax = max(rightMax, height[end]);

        if(leftMax < rightMax){
            water += leftMax - height[start];
            start++;
        }
        else{
            water += rightMax - height[end];
            end--;
        }
    }
    return water;
  }
}