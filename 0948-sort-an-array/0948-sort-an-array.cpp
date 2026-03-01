class Solution {
    vector<int> merge(vector<int> &left, vector<int> &right){
        int len1 = left.size();
        int len2 = right.size();
        int a1 = 0, a2 = 0;
        int k = 0;
        vector<int> temp(len1 + len2);

        while(a1 < len1 and a2 < len2){
            if(left[a1] <= right[a2]){
                temp[k++] = left[a1++];
            }
            else{
                temp[k++] = right[a2++];
            }
        }

        while(a1 < len1){
            temp[k++] = left[a1++];
        }

        while(a2 < len2){
            temp[k++] = right[a2++];
        }

        return temp;

        // for(int i = l, j = 0; i <= r; i++){
        //     nums[i] = temp[j++];
        // }

    }

    vector<int> solve(vector<int> &nums, int l, int r){
        if(l == r) return {nums[l]};

        int mid = (l + r) / 2;
        vector<int> left = solve(nums, l, mid);
        vector<int> right = solve(nums, mid + 1, r);
        return merge(left, right);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n-1);
    }
};