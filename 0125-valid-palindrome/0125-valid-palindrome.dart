class Solution {
  bool isPalindrome(String s) {
    //approch 1:
    // String temp = "";
    // for(var x in s.split('')){
    //     if(RegExp(r'^[a-zA-Z0-9]+$').hasMatch(x)){
    //         temp += x.toLowerCase();
    //     }
    // }

    // print(temp);

    // int n = temp.length;
    // for(int i = 0; i < n/2; i++){
    //     if(temp[i] != temp[n-i-1]){
    //         return false;
    //     }
    // }
    // return true;

    //approch 2:
    String cleaned = s.toLowerCase().replaceAll(RegExp(r'[^a-z0-9]'), '');
    print(cleaned);
    int i = 0;
    int j = cleaned.length-1;

    while(i < j){
        if(cleaned[i] != cleaned[j]){
            return false;
        }
        i++; j--;
    }
    return true;
  }
}