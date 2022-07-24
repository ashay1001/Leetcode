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

class NodeValue{
public:
    int minNode, maxNode, maxSum;
    bool isBST;
    NodeValue(int minNode, int maxNode, int maxSum, bool check)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
        this->isBST = check;
    }
};

class Solution {
public:
    int ans = 0;
    NodeValue solve(TreeNode *root)
    {
        if(!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0, true);
        }
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        NodeValue currNode(INT_MIN,INT_MAX, 0, false);
        currNode.maxSum = left.maxSum + right.maxSum + root->val;
        currNode.minNode = min(root->val, left.minNode);
        currNode.maxNode = max(root->val, right.maxNode);
        
        if(left.isBST and right.isBST and (left.maxNode < root->val) and (right.minNode > root->val))
        {
            ans = max(ans,currNode.maxSum);
            currNode.isBST = true;
        }
        else
            currNode.isBST = false;
        
        return currNode;
    }
    
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};