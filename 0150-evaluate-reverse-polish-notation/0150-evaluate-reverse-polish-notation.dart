import 'dart:collection';

int perform(int first, String expression, int second){
    if(expression == '+') return first + second;
    else if(expression == '-') return first - second;
    else if(expression == '*') return first * second;
    else return first ~/ second;
}

class Solution {
  int evalRPN(List<String> tokens) {
    List<int> number = [];

    for(var i in tokens){
        if(i == '+' || i == '-' || i == '*' || i == '/'){
            int second = number.last;
            number.removeLast();
            int first = number.last;
            number.removeLast();

            number.add(perform(first, i, second));
        }
        else number.add(int.parse(i));
    }

    return number[0];
  }
}