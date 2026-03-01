class Solution {
public:
    void sortColors(vector<int>& nums) {
        //approch 1:
        // int r, w, b;
        // r = w = b = 0;

        // for(int x : nums){
        //     if(x == 0) r++;
        //     else if(x == 1) w++;
        //     else b++;
        // }

        // int i = 0;
        // while(r--){
        //     nums[i++] = 0;
        // }

        // while(w--){
        //     nums[i++] = 1;
        // }

        // while(b--){
        //     nums[i++] = 2;
        // }


        //approch 2: using three pointers
        int n = nums.size();
        int l = 0, r = n - 1, i = 0;

        while(i <= r){
            if(nums[i] == 0){
                swap(nums[i++], nums[l++]);
            }

            else if (nums[i] == 2){
                swap(nums[i], nums[r--]);
            }
            else{
                i++;
            }
        }
    }
};