//https://leetcode.com/problems/binary-tree-right-side-view/description/

//approch 1: dfs and map
//o(nlogn) time
//o(n) space 

void solve(TreeNode* root, int hd, int level, map<int, pair<int, int>> &mp){
    //map<level, (hd, value)>
    if(root == NULL) return;
    
    mp[level] = {hd, root->val}; //overwriting
    
    solve(root->left, hd-1, level+1, mp);
    solve(root->right, hd+1, level+1, mp);
}

class Solution {
public:
   vector<int> rightSideView(TreeNode* root) {
       map<int, pair<int, int>> mp;
       vector<int> ans;
       
       solve(root, 0, 0, mp);
       for(auto x : mp){
           ans.push_back(x.second.second);
       }
       return ans;
   }
};


//approch 2 : bfs and map
//o(nlogn) time
//o(n) space

class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            map<int, int> mp;
            vector<int> ans;
            if(root == NULL) return {};
            queue<pair<TreeNode*, int>> q;
            q.push({root, 0});
    
            while(!q.empty()){
                auto front = q.front();
                q.pop();
                TreeNode* node = front.first;
                int lvl = front.second;
    
                mp[lvl] = node->val;
    
                if(node->left){
                    q.push({node->left, lvl+1});
                }
                if(node->right){
                    q.push({node->right, lvl+1});
                }
            }
    
            for(auto x : mp){
                ans.push_back(x.second);
            }
            return ans;
        }
    };


//approch 3 : bfs and NO map
//time : o(n)
//space: => o(maximum width, for queue) + o(maximum height, for vector)
//       => o(maximum width) 

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int last_val = 0;

            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();

                last_val = node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(last_val);
        }

        return ans;
    }
}


//approch 4 : eassy pessy
//o(n) time and space

class Solution {
    void solve(TreeNode* root, int level, vector<int> &v){
        if(root == NULL) return;
        if(level == v.size()) v.push_back(root->val);
        
        solve(root->right, level+1, v);
        solve(root->left, level+1, v);
    }
   
   public:
       vector<int> rightSideView(TreeNode* root) {
           vector<int> ans;
           solve(root, 0, ans);
   
           return ans;
       }
};