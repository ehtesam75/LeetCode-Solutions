//https://leetcode.com/problems/balanced-binary-tree/description/

//approch 1
//o(n^2) time
class Solution {
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return 1;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool checkHeight = abs(height(root->left) - height(root->right)) <= 1;

        if(left and right and checkHeight){
            return 1;
        }
        else{
            return 0;
        }
    }
};


//approch 2
//o(n) time

pair<bool, int> is_balanced(TreeNode* root){
    if(root == NULL){
        return {true, 0};
    }

    pair<bool, int> left = is_balanced(root->left);
    pair<bool, int> right = is_balanced(root->right);

    bool op1 = left.first;  //left side balanced?
    bool op2 = right.first; //right side balanced?
    bool op3 = abs(left.second - right.second) <= 1;    //is this node balanced?

    int height = max(left.second, right.second) + 1;
    bool balanced = op1 and op2 and op3;
    return {balanced, height};
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return is_balanced(root).first;
    }
};