//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

//approch 1:
//o(nlogn)

class Solution {
    private:
        void solve(TreeNode* root, int row_idx, int col_idx, vector<vector<pair<int, int>>> &v){
            if(root == NULL){
                return;
            }
    
            int re_idx = col_idx < 0 ? (abs(col_idx) + 1000) : col_idx;
            v[re_idx].push_back({row_idx, root->val});
    
            solve(root->left, row_idx + 1, col_idx - 1, v);
            solve(root->right, row_idx + 1, col_idx + 1, v);
        }
    
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<pair<int, int>>> ans(2000);
            vector<vector<int>> res;
    
            solve(root, 0, 0, ans);
            for(int i = ans.size()-1; i >= 1001; i--){
                if(!ans[i].empty()){
                    sort(ans[i].begin(), ans[i].end());
                    vector<int> temp;
                    for(auto x : ans[i]){
                        temp.push_back(x.second);
                    }
                    res.push_back(temp);
                }
            }
    
            for(int i = 0; i <= 1000; i++){
                if(!ans[i].empty()){
                    sort(ans[i].begin(), ans[i].end());
                    vector<int> temp;
                    for(auto x : ans[i]){
                        temp.push_back(x.second);
                    }
                    res.push_back(temp);
                }
            }
    
            return res;
        }
    };



//approch 2: using map
//o(nlogn) time
//o(n) space

class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
             map<int, map<int, vector<int>>> mp; //map<horizontal_distance, map<level, vector>>> mp
             queue<pair<TreeNode*, pair<int, int>>> q; //queue<node*, (horizontal_distance, level)>
             vector<vector<int>> res;
    
             q.push({root, {0, 0}});
             
             while(!q.empty()){
                 auto curr = q.front();
                 q.pop();
                 
                 int value = curr.first->val;
                 int hd = curr.second.first;
                 int level = curr.second.second;
                 
                 mp[hd][level].push_back(value);
                 
                 if(curr.first->left){
                     q.push(make_pair(curr.first->left, make_pair(hd-1, level+1)));
                 }
                 if(curr.first->right){
                     q.push(make_pair(curr.first->right, make_pair(hd+1, level+1)));
                 }
             }
             
             for(auto [x, y] : mp){
                vector<int> temp;
                for(auto [a, b] : y){
                    sort(b.begin(), b.end());
                    for(auto value : b){
                        temp.push_back(value);
                    }
                }
                res.push_back(temp);
            }
            return res;
        }
    };