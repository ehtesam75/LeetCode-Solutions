class Solution {
  bool isUgly(int n) {
    if(n <= 0) return false;

    for(int f in [2, 3, 5]){
        while(n % f == 0){
            n = n ~/ f;
        }
    }

    return n == 1;
  }
}