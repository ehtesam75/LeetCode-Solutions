class Solution {
public:
    int majorityElement(vector<int>& nums) {

        //approch 1 : nlogn
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // return nums[n/2];

        //approch 2 : o(n)
        int counter = 0;
        int candidate = 0;

        for(int i = 0; i < nums.size(); i++){
            if(counter == 0){
                candidate = nums[i];
                counter = 1;
            }
            else if(nums[i] == candidate) counter++;
            else counter--;
        }
        return candidate;
    }
};