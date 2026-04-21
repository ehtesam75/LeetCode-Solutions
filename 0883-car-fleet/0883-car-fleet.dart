class Solution {
  int carFleet(int target, List<int> position, List<int> speed) {
    List<(int, double)> temp = [];
    for(int i = 0; i < position.length; i++){
        double time = (target - position[i]) / speed[i];
        temp.add((position[i], time));
    }

    temp.sort((a, b) => b.$1.compareTo(a.$1));

    int ans = 1;
    double fleet_max_time = temp[0].$2;
    for(int i = 1; i < position.length; i++){
        if(temp[i].$2 > fleet_max_time){
            ans++;
            fleet_max_time = temp[i].$2;
        }
    }
    return ans;
  }
}