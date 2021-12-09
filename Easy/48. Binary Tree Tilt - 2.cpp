class Solution {
public:
    
    int findTilt(TreeNode* root) {
        calcTilt(root);
        return addSum(root);
    }
    
    int calcTilt(TreeNode *root)
    {
        if(!root) return 0;
        
        int leftSum = calcTilt(root->left);
        int rightSum = calcTilt(root->right);
        int total = leftSum + rightSum + root->val;
        root->val = abs(leftSum - rightSum);
        return total;
    }
    
    int addSum(TreeNode *root)
    {
        int ans = 0;
        if(!root) return 0;
        ans += addSum(root->left) + addSum(root->right) + root->val;
        return ans;
    }
};