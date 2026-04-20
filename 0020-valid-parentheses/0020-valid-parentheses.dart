  bool compatible(String a, String b){
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
  }

class Solution {
  bool isValid(String s) {
    List<String> stack = [];

    for(var i in s.split('')){
        if(i == '(' || i == '[' || i == '{'){
            stack.add(i);
        }
        else{
            if(stack.isEmpty) return false;
            if(!compatible(stack.last, i)) return false;
            else stack.removeLast();
        }
    }

    if(stack.isEmpty) return true;
    else return false;
  }
}