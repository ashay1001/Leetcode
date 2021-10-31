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
    vector<int> inorderTraversal(TreeNode* root) {
        
        // create an empty stack
	    stack<TreeNode*> stack;
        vector<int> res;
	    // start from the root node (set current node to the root node)
	    TreeNode* curr = root;

	    // if the current node is null and the stack is also empty, we are done
	    while (!stack.empty() || curr != nullptr)
	    {
		    // if the current node exists, push it into the stack (defer it)
		    // and move to its left child
		    if (curr != nullptr)
		    {
			    stack.push(curr);
			    curr = curr->left;
		    }
		    else {
			    // otherwise, if the current node is null, pop an element from the                  stack,
			    // print it, and finally set the current node to its right child
			    curr = stack.top();
			    stack.pop();
			    res.push_back(curr->val);
    			curr = curr->right;
		    }
	    }
        return res;
    }
};