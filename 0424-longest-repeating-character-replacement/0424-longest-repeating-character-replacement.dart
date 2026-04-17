class Solution {
  int characterReplacement(String s, int k) {
    int n = s.length;
    Map<String, int> freq = {};

    int left = 0, right = 0;
    int ans = 0;

    while(right < n){
        freq[s[right]] = (freq[s[right]] ?? 0) +1;

        int maxFreq = freq.values.reduce((a, b) => a > b ? a : b);
        // print(maxFreq);
        int windowSize = right - left + 1;
        if(windowSize - maxFreq > k){
            freq[s[left]] = freq[s[left]]! - 1;
            left++;
            // freq[s[left]] = freq[s[left]]! - 1;
            // left++;
        }

        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
  }
}