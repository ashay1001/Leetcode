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
    vector<int> postorderTraversal(TreeNode* root) {
       if(root == NULL) return {};
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        // create another stack to store postorder traversal
        stack<int> out;
     
        // loop till stack is empty
        while (!s.empty())
        {
            // pop a node from the stack and push the data into the output stack
            TreeNode* curr = s.top();
            s.pop();
 
            out.push(curr->val);
 
            // push the left and right child of the popped node into the stack
            if (curr->left) {
                s.push(curr->left);
            }
 
            if (curr->right) {
                s.push(curr->right);
            }
        }
 
        // print postorder traversal
        while (!out.empty())
        {
            res.push_back(out.top());
            out.pop();
        }
    return res;
    }
};