//https://leetcode.com/problems/path-sum/description/

//approch 1 : 
//o(n) time and o(h) space

class Solution {
    private:
        bool solve(TreeNode* root, int sum, int target){
            if(root == NULL){
                return false;
            }
    
            if(root->left == NULL and root->right == NULL){
                sum += root->val;
                if(sum == target) return true;
                else return false;
            }
    
            bool left = solve(root->left, sum + root->val, target);
            bool right = solve(root->right, sum + root->val, target);
    
            if(left or right) return true;
            else return false;
        }
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {
            if(root == NULL) return false;
            return solve(root, 0, targetSum);
        }
    };


//approch 2:
//same complexity

class Solution {
    bool ans = 0;
    void solve(TreeNode* root, int targetSum, int currentSum){
        if(root == NULL){
            return;
        }

        currentSum += root->val;
        if(root->left == NULL and root->right == NULL){
            if(targetSum == currentSum){
                ans = 1;
            }
        }
        solve(root->left, targetSum, currentSum);
        solve(root->right, targetSum, currentSum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        solve(root, targetSum, 0);
        return ans;
    }
};