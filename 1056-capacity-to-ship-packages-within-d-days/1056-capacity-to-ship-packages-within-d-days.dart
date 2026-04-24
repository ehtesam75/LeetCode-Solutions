bool f(int maxWeights, List<int> weights, int maxDays){
    int n = weights.length;
    int days = 1, w = 0;

    for(int i = 0; i < n; i++){
        if(weights[i] > maxWeights){
            return false;
        }
    }

    for(int i = 0; i < n; i++){
        w += weights[i];
        if(w > maxWeights){
            days++;
            w = weights[i];
        }
    }
    return days <= maxDays;
}

class Solution {
  int shipWithinDays(List<int> weights, int days) {
    int l = 0, r = 1000000000;
    int ans = -1;
    while(l <= r){
        int mid = l + (r-l)~/2;
        if(f(mid, weights, days)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
  }
}