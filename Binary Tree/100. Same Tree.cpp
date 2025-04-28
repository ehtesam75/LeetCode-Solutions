//https://leetcode.com/problems/same-tree/description/

//approch 1
// //o(n) time and o(h) space

//space complexity:
//o(height) 
// = o(log n) (2 base) [here n = number of nodes] (for a balanced tree)
// (h == log n for a balanced tree)
//when h == n (for a skewed tree, like a stright line) sc = o(n)

class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(p == NULL and q == NULL){
                return 1;
            }
            else if((p == NULL and q != NULL) or (p != NULL and q == NULL)){
                return 0;
            }
    
            bool left = isSameTree(p->left, q->left);
            bool right = isSameTree(p->right, q->right);
    
            return (left and right and (p->val == q->val));
            //left true
            //right true
            //both values of p and q are same
            //..then return true
        }
    };