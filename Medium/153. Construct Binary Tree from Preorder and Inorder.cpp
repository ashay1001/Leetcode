class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;
        
        
        return solve(preorder, 0, inorder.size()-1, preIndex, mp);
    }
    
    TreeNode* solve(vector<int>& preorder, int left, int right, int &preIndex, unordered_map<int, int> &mp)
    {
        if(left > right) return NULL;
        
        int rootVal = preorder[preIndex];
        preIndex++;
        TreeNode *root = new TreeNode(rootVal);
        
        root->left = solve(preorder, left, mp[rootVal]-1, preIndex, mp);
        root->right = solve(preorder, mp[rootVal]+1, right, preIndex, mp);
        
        return root;
    }
};