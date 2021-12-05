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
    int rob(TreeNode* root) {
     /* ---------------without optimization--------------
     
        if(!root) {return 0;}
        int sum = 0;
        
        if(root->left != NULL)
            sum = sum + rob(root->left->left) + rob(root->left->right);
        
        if(root->right != NULL)
            sum = sum + rob(root->right->left) + rob(root->right->right);
        
        return max(sum + root->val, rob(root->left) + rob(root->right));
        -----------------------------------------------------------------
    */
        
        unordered_map<TreeNode*, int> mp;
        return robUtil(root, mp);
    }
    
    int robUtil(TreeNode *root, unordered_map<TreeNode*, int> &mp)
    {
        int sum = 0;
        if(!root) return 0;
        
        if(mp.find(root) != mp.end())
            return mp[root];
        
        if(root->left != NULL)
            sum = sum + robUtil(root->left->left, mp) + robUtil(root->left->right, mp);
        
        if(root->right != NULL)
            sum = sum + robUtil(root->right->left, mp) + robUtil(root->right->right, mp);
        
        sum = max(sum + root->val, robUtil(root->left, mp) + robUtil(root->right, mp));
        mp[root] = sum;
        
        return sum;
    }
};