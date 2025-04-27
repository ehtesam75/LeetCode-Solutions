//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/


// approch 1:
//tc : o(n) ; cuz each node is visited once
//sc : o(max height), in worst case (sqcue tree) it will be o(n) (as height = n)

class Solution {
    private:
    void solve(TreeNode* root, int &ans, int count){
        if(root == NULL){
            ans = max(ans, count);
            return;
        }
    
        solve(root->left, ans, count + 1);
        solve(root->right, ans, count + 1);
    }
    
    public:
        int maxDepth(TreeNode* root) {
            int ans = 0, count = 0;
            solve(root, ans, count);
            return ans;
        }
    };


//approch 2:
//tc : o(n)
//sc : o(max  height)

class Solution {

    public:
        int maxDepth(TreeNode* root) {
            if(root == NULL) return 0;
    
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
    
            int count = max(left, right) + 1;
            // for a node get the max height of left and right sub tree then add the 1 (the node itself)
            //recurssion will handle the rest of the tree

            return count;
        }
    };
