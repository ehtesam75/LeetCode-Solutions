class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r, w, b;
        r = w = b = 0;

        for(int x : nums){
            if(x == 0) r++;
            else if(x == 1) w++;
            else b++;
        }

        int i = 0;
        while(r--){
            nums[i++] = 0;
        }

        while(w--){
            nums[i++] = 1;
        }

        while(b--){
            nums[i++] = 2;
        }
    }
};