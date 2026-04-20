class Solution {
  String minWindow(String s, String t) {
    Map<String, int> freq1 = {};
    Map<String, int> freq2 = {};
    Map<String, int> afterStartFound = {};
    int start = -1, unique = 0;

    for (int i = 0; i < s.length; i++) {
      freq1[s[i]] = (freq1[s[i]] ?? 0) + 1;
    }

    for (int i = 0; i < t.length; i++) {
      if (!freq2.containsKey(t[i])) unique++;
      freq2[t[i]] = (freq2[t[i]] ?? 0) + 1;
    }

    String ans = "";
    for (int i = 0; i < t.length; i++) {
      if ((freq2[t[i]] ?? 0) > (freq1[t[i]] ?? 0)) return ans;
    }

    for (int i = 0; i < s.length; i++) {
      if (freq2.containsKey(s[i])) {
        start = i;
        break;
      }
    }

    if (start == -1) return ans;

    int left = start;

    for (int right = start; right < s.length; right++) {
      String rc = s[right];
      afterStartFound[rc] = (afterStartFound[rc] ?? 0) + 1;
      if ((freq2[rc] ?? 0) > 0 && afterStartFound[rc] == freq2[rc]) {
        unique--;
      }

      while (unique == 0) {
        String candidate = s.substring(left, right + 1);
        if (ans.isEmpty || candidate.length < ans.length) {
          ans = candidate;
        }
        String lc = s[left];
        afterStartFound[lc] = afterStartFound[lc]! - 1;
        if ((freq2[lc] ?? 0) > 0 && afterStartFound[lc]! < freq2[lc]!) {
          unique++; 
        }
        left++;
      }
    }

    return ans;
  }
}