//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

//approch 1:
//o(n) time and o(h) space

class Solution {
    private:
        bool solve(TreeNode* root, TreeNode* a, TreeNode* b, TreeNode* &ans){
            if(root == NULL) return 0;
              
            bool present_left = solve(root->left, a, b, ans);
            bool present_right = solve(root->right, a, b, ans);
            
            bool present_in_curr = (root->val == a->val or root->val == b->val);
            
            if((present_left and present_right) or (present_left and present_in_curr) or (present_right and present_in_curr)){
                ans = root;
            }
            
            return (present_left or present_right or present_in_curr);
        }
    
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode* ans = NULL;
            bool check = solve(root, p, q, ans);
            return ans;
        }
    };



//approch 2:
//same complexity

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == NULL) return NULL;
    
            if(root->val == p->val or root->val == q->val){
                return root;
            }
    
            auto left = lowestCommonAncestor(root->left, p, q);
            auto right = lowestCommonAncestor(root->right, p, q);
    
            if(left and right){
                return root;
            }
            else if(left and !right){
                return left;
            }
            else if(!left and right){
                return right;
            }
            else return NULL;
        }
    };