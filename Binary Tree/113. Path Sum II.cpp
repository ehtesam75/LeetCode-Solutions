//https://leetcode.com/problems/path-sum-ii/description/

//approch 1
//complexity is discussed in details
//time : o(n + k * h)
//space : o(h + k * h)


class Solution {
    void solve(TreeNode* root, int sum, int target, vector<int> path, vector<vector<int>> &ans){
        if(root == NULL){
            return;
        }
        
        //time : o(n) for visiting all nodes
        //space : o(h) for recurssion stack

        path.push_back(root->val);
        sum += root->val;
        if(root->left == NULL and root->right == NULL){
            if(sum == target){
                ans.push_back(path);
                //say there are k path
                //each has height amount of node at once, at worst case
                //time : o(k * h) for coping path vector to ans vector

                //space : o(k * h) [k path, each can have h amount of node]
            }
            return;
        }

        solve(root->left, sum, target, path, ans);
        solve(root->right, sum, target, path, ans);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        solve(root, 0, targetSum, {}, ans);
        return ans;
    }
};