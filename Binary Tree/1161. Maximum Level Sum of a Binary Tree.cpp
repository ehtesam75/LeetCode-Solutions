//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

//approch 1
//o(n) time and o(maximum width) space

class Solution {
    public:
        int maxLevelSum(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
    
            int curr_level = 1;
            int sum = 0;
            int maxi_sum = INT_MIN;
            int level = -1;
    
            while(!q.empty()){
                TreeNode* front = q.front();
                q.pop();
    
                if(front == NULL){
                    if(!q.empty()){
                        q.push(NULL);
                    }
                    if(sum > maxi_sum){
                        level = curr_level;
                        maxi_sum = sum;
                    }
                    curr_level++;
                    sum = 0;
                }
                else{
                    sum += front->val;
    
                    if(front->left != NULL){
                        q.push(front->left);
                    }
                    if(front->right != NULL){
                        q.push(front->right);
                    }
                }
            }
    
            return level;
        }
    };



//approch 2:
//o(n) time and o(maximum width of binary tree) space

class Solution {
    public:
        int maxLevelSum(TreeNode* root) {
            int maximum = INT_MIN;
            int ans = 1;
            queue<TreeNode*> q;
            q.push(root);
            int level = 0;
    
            while(!q.empty()){
                int size = q.size();
                int sum = 0;
                level++;
    
                for(int i = 0; i < size; i++){
                    auto node = q.front();
                    q.pop();
                    sum += node->val;
    
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                if(sum > maximum){
                    maximum = sum;
                    ans = level;
                }
            }
            return ans;
        }
    };