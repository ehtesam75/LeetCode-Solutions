//binary search approch : O(logn)

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        if(it == letters.end()){
            return letters[0];
        }
        else{
            return *it;
        }
    }
};

//https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/

