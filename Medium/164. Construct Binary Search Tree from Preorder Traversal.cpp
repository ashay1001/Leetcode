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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder.begin(), preorder.end());
        unordered_map<int, int> mp;
        sort(inorder.begin(), inorder.end());
        
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;
        int preIndex = 0;
        return solve(preorder, 0, inorder.size()-1, preIndex, mp);
    }
    
    TreeNode* solve(vector<int> &preorder, int left, int right, int &preIndex, unordered_map<int,int> &mp)
    {
        if(left > right) return NULL;
        TreeNode *root = new TreeNode(preorder[preIndex++]);
        root->left = solve(preorder, left, mp[root->val]-1, preIndex, mp);
        root->right = solve(preorder, mp[root->val]+1, right, preIndex, mp);
        return root;
    }
};