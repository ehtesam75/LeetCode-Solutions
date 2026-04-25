class TimeMap {
  Map<String, List<(int, String)>> mp = {};
  TimeMap() {
    
  }
  
  void set(String key, String value, int timestamp) {
    if(mp[key] == null) mp[key] = [];
    mp[key]!.add((timestamp, value));
  }
  
  String get(String key, int timestamp) {
    if(mp[key] == null) return "";
    List<(int, String)> temp = mp[key]!;
    int n = temp.length;
    int l = 0, r = n-1, ans = -1;
    while(l <= r){
        int mid = l + (r-l)~/2;
        if(temp[mid].$1 <= timestamp){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    if(ans == -1) return "";
    else return temp[ans].$2;
  }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = TimeMap();
 * obj.set(key,value,timestamp);
 * String param2 = obj.get(key,timestamp);
 */