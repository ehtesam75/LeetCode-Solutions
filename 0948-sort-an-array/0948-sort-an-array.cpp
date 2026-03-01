class Solution {
    void merge(vector<int> &nums, int l, int mid, int r, vector<int> &temp){
        int i = l, j = mid + 1, k = l;

        while(i <= mid and j <= r){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }

        while(i <= mid){
            temp[k++] = nums[i++];
        }

        while(j <= r){
            temp[k++] = nums[j++];
        }

        for(int i = l; i <= r; i++){
            nums[i] = temp[i];
        }
    }

    void solve(vector<int> &nums, int l, int r, vector<int> &temp){
        if(l >= r) return;

        int mid = (l + r) / 2;
        solve(nums, l, mid, temp);
        solve(nums, mid + 1, r, temp);
        merge(nums, l, mid, r, temp);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp (n);
        solve(nums, 0, n-1, temp);
        return nums;
    }
};