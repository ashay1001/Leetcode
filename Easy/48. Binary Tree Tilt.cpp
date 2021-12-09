class Solution {
public:
    int findTilt(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        tilt(root, mp);
        return sum(root);
    }
    
    int tilt(TreeNode *root, unordered_map<TreeNode*, int> &mp)
    {
        int sum = 0;
        if(!root) return 0;
        
        if(mp.find(root) != mp.end())
            return mp[root];
        
        int lsum = tilt(root->left, mp);
        int rsum = tilt(root->right, mp);
        sum = sum + lsum + rsum + root->val;
        mp[root] = sum;
        root->val = abs(lsum - rsum);
        return sum;
    }
    
    int sum(TreeNode *root)
    {
        if(!root) return 0;
        
        int totalsum = root->val + sum(root->left) + sum(root->right);
        return totalsum;
    }
};