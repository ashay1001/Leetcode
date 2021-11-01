class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
     
        if(root == NULL) {return false;}
        targetSum -= root->val;
        if(targetSum == 0 && root->left == NULL && root->right == NULL) {return true;}
        
        bool left = hasPathSum(root->left, targetSum);
        bool right = hasPathSum(root->right, targetSum);
        
        return left || right;
    }
};