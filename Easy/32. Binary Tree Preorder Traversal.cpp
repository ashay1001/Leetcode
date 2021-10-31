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
    vector<int> preorderTraversal(TreeNode* root) {
     
    vector<int> res;
	if (root == nullptr)
	return {};

	// create an empty stack and push the root node
	stack<TreeNode*> stack;
	stack.push(root);

	// loop till stack is empty
	while (!stack.empty())
	{
		// pop a node from the stack and print it
		TreeNode* curr = stack.top();
		stack.pop();
        res.push_back(curr->val);    

		// push the right child of the popped node into the stack
		if (curr->right) {
			stack.push(curr->right);
		}

		// push the left child of the popped node into the stack
		if (curr->left) {
			stack.push(curr->left);
		}

		// the right child must be pushed first so that the left child
		// is processed first (LIFO order)
    }
    return res;
}
};