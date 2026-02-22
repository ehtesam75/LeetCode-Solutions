class Solution {
    bool isValid(int n, int x){
        return (1ll * n * n <= x);
    }
public:
    int mySqrt(int x) {
        int l = 0, r = 1e5;
        int ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(isValid(mid, x)){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};