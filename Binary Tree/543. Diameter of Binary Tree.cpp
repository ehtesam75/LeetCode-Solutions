//https://leetcode.com/problems/diameter-of-binary-tree/description/

//approch 1:
//time : o(n^2)
//spcae :o(height)
class Solution {
    private:
        int maxHeight(TreeNode* root){
            if(root == NULL){
                return 0;
            }
    
            int left = maxHeight(root->left);
            int right = maxHeight(root->right);
    
            int ans = max(left, right) + 1;
            return ans;
        }
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            if(root == NULL){
                return 0;
            } 
            
            int op1 = diameterOfBinaryTree(root->left);
            int op2 = diameterOfBinaryTree(root->right);
            int op3 = maxHeight(root->left) + maxHeight(root->right);
            return max(op1, max(op2, op3));
        }
    };



//approch 2:
//o(n) time
class Solution {
    private:
        pair<int, int> diameterFast(TreeNode* root){
            if(root == NULL){
                pair<int, int> a = make_pair(0, 0);
                return a;
            }

            pair<int, int> op;
            pair<int, int> left = diameterFast(root->left);
            pair<int, int> right = diameterFast(root->right);
            int op1 = left.first;
            int op2 = right.first;
            int op3 = left.second + right.second;

            int diameter = max(op1, max(op2, op3));
            int max_height = max(left.second, right.second) + 1;
            return {diameter, max_height};
        }

    public:
        int diameterOfBinaryTree(TreeNode* root) {
            return diameterFast(root).first;
        }
    };



//approch 3:
//o(n)

class Solution {
    private:
    int solve(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        
                int left = solve(root->left, ans);
                int right = solve(root->right, ans);
        
                int sub_ans = left + right;
                ans = max(ans, sub_ans);
    
                int count = max(left, right) + 1;
                return count;
    }
    public:
        int diameterOfBinaryTree(TreeNode* root) {
             int ans = 0;
             solve(root, ans);
             return ans;
        }
};