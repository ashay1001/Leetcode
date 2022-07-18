/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        
        q.push({root, {0, 0}});
        while(!q.empty())
        {
            auto it = q.front(); q.pop();
            TreeNode *node = it.first;
            int x_axis = it.second.first;
            int y_axis = it.second.second;
            mp[x_axis][y_axis].insert(node->val);
            
            if(node->left != NULL) {
                q.push({node->left, {x_axis-1, y_axis+1}}); 
            }
            if(node->right != NULL) {
                q.push({node->right, {x_axis+1, y_axis+1}}); 
            }
        }

        for(auto x : mp)
        {
            vector<int> column;
            for(auto y : x.second)
            {
                column.insert(column.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(column);
        }  
        return ans;
    }
};