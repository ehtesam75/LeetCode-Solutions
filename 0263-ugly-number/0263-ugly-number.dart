class Solution {
  bool isUgly(int n) {
    if(n <= 0) return false;

    while(n % 2 == 0){
        n = n ~/ 2;
    }

    for(int i = 3; i <= 5; i += 2){
        while(n % i == 0){
            n = n ~/ i;
        }
    }

    if(n > 1){
        return false;
    }
    return true;
  }
}