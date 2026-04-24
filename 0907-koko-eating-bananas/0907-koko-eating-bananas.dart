bool f(int speed, List<int> piles, int h){
    int n = piles.length,  time = 0;
    for(int i = 0; i < n; i++){
        time += (piles[i]/speed).ceil();
    }
    return time <= h;
}

class Solution {
  int minEatingSpeed(List<int> piles, int h) {
    int l = 1, r = 1000000000;
    int ans = 0;

    while(l <= r){
        int mid = l + (r-l)~/2;
        if(f(mid, piles, h)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
  }
}