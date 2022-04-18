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
    int ans = 0;
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        solve(root);
        return ans;
    }
    
    void solve(TreeNode *root)
    {
        if(root->left)
            solve(root->left);
        
        count--;
        
        if(count == 0) 
        {
            ans = root->val;
            return;
        }
        if(root->right)
            solve(root->right);
    }
};