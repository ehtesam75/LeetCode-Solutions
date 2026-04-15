class Solution {
  int lengthOfLongestSubstring(String s) {
    Map<String, int> mp = {};
    int left = 0, right = 0;
    int maxLength = 0;

    for(int i = 0; i < s.length; i++){  //o(n)   
        
        if(mp.containsKey(s[i])){
            // maxLength = max(maxLength, );
            // mp[s[i]] = i;
            // // atLeastOneDup = true;
            // currentLength = i - lastDuplicate;
            // lastDuplicate = i;

            int lastPos = mp[s[i]]!;
            if(lastPos >= left){
                maxLength = max(maxLength, right - left);
                left = lastPos + 1;
            }
        } 

        mp[s[i]] = i;
        right++;
    }

    return max(maxLength, right - left);
  }
}