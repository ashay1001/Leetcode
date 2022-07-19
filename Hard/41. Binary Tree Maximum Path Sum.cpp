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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
    
    int solve(TreeNode *root, int &ans)
    {
        if(!root) return 0;
        
        int leftSum = max(0, solve(root->left, ans));
        int rightSum = max(0, solve(root->right, ans));
        
        ans = max(ans, leftSum + rightSum + root->val);
        
        return root->val + max(leftSum, rightSum);
    }
};