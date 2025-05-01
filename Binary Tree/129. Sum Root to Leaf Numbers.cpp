//https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

//approch 1:
//o(N) time and o(h) space

class Solution {
    void solve(TreeNode* root, string path, int &total_sum){
        if(root == NULL){
            return;
        }

        path += root->val + '0';
        if(root->left == NULL and root->right == NULL){
            total_sum += stoi(path);
        }

        solve(root->left, path, total_sum);
        solve(root->right, path, total_sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root, "", ans);
        return ans;
    }
};


//approch 2:
//same complexity

class Solution {

    void solve(TreeNode* root, int &sum, int number){
        if(root == NULL) return;
    
        number = number * 10 + root->val;
    
        if(root->left == NULL and root->right == NULL){
            sum = sum + number;
            return;
        }
    
        solve(root->left, sum, number);
        solve(root->right, sum, number);
    }
    
    public:
        int sumNumbers(TreeNode* root) {
            int sum = 0;
            int number = 0;
            solve(root, sum, number);
            return sum;
        }
    };