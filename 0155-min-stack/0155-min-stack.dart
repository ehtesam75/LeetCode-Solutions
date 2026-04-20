class MinStack {

    List<int> st = [];
  MinStack() {
  }
  
  void push(int val) {
    st.add(val);
  }
  
  void pop() {
    if(st.isNotEmpty){
        st.removeLast();
    }
  }
  
  int top() {
    return st.last;
  }
  
  int getMin() {
    int mini = (1 << 31);
    for(int i = 0; i < st.length; i++){
        mini = min(mini, st[i]);
    }
    return mini;
  }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = MinStack();
 * obj.push(val);
 * obj.pop();
 * int param3 = obj.top();
 * int param4 = obj.getMin();
 */