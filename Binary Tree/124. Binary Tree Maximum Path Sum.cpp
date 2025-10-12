//https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

//approch 1:
//o(n) time and o(h) space

class Solution {
    int ans = INT_MIN;
private:
    int solve(TreeNode* root){
        if(root == NULL) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int max_portion_return = max(root->val, max(root->val + left, root->val + right));
        int total_max_portion = max(root->val + left + right, max_portion_return);

        ans = max(ans, total_max_portion);
        return max_portion_return;
    }
public:
    int maxPathSum(TreeNode* root) {
        int check = solve(root);
        return ans;
    }
};