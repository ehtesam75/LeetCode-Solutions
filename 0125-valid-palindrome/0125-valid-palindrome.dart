class Solution {
  bool isPalindrome(String s) {
    String temp = "";
    for(var x in s.split('')){
        if(RegExp(r'^[a-zA-Z0-9]+$').hasMatch(x)){
            temp += x.toLowerCase();
        }
    }
    print(temp);

    int n = temp.length;
    for(int i = 0; i < n/2; i++){
        if(temp[i] != temp[n-i-1]){
            return false;
        }
    }
    return true;
  }
}