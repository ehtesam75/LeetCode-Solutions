class Solution {
  bool checkInclusion(String s1, String s2) {
    int n2 = s2.length;
    Map<String, int> freq = {};
    int unique = 0, left = 0, right = 0;

    for(int i = 0; i < s1.length; i++){
        if(freq[s1[i]] == null || freq[s1[i]] == 0) unique++;
        freq[s1[i]] = (freq[s1[i]] ?? 0) +1;
    }

    while(right < n2){
        if(!freq.containsKey(s2[right])){
            while(left < right){
                if(freq[s2[left]] == 0) unique++;
                freq[s2[left]] = freq[s2[left]]! + 1;
                left++;
            }
            left++; right++;
            continue;
        }
        else if(freq.containsKey(s2[right])){
            freq[s2[right]] = freq[s2[right]]! - 1;
            if(freq[s2[right]] == 0){
                unique--;
            }
            
            //window size exceeds s1
            while(right - left + 1 > s1.length){
                if(freq[s2[left]] == 0) unique++;
                freq[s2[left]] = freq[s2[left]]! + 1;
                left++;
            }
            if(unique == 0) return true;
        }
        right++;
    }
    return false;
  }
}