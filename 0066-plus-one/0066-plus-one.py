class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        if(digits[n-1] != 9):
            digits[n-1] += 1
            return digits
        
        i = n-1
        while(digits[i] == 9):
            digits[i] = 0
            i -= 1
        
        ans = []
        if(i >= 0): 
            digits[i] += 1
        else: ans += [1]
        ans += digits
        return ans