class Solution {
public:
    // Helper Class
    class Helper {
        public: 
        int maxi, mini, sum, isBST;
        Helper() {
            maxi = -40000; mini = 40000; sum = 0; isBST = 1;
        }
    };
    // Default object for base case
    Helper hh;
    // This will store the max sum for a BST
    int maxSum = 0;
    Helper dfs(TreeNode *root) {
        if(!root) {
            return hh;
        }
        Helper l = dfs(root->left);
        Helper r = dfs(root->right);
        Helper h;
        // If either of the subtrees is not BST, subtree through current node cannot be BST
	    // Also if current node is less than the maximum node of left subtree or greater than
	    // the minimum node of right subtree, it can't be a bst
        if(!l.isBST || !r.isBST || root->val <= l.maxi || root->val >= r.mini) {
            h.isBST = 0;
            return h;
        }
        // If a BST is formed through current node
        h.sum = l.sum + r.sum + root->val;
        maxSum = max(maxSum, h.sum);
        h.mini = min(l.mini, root->val);
        h.maxi = max(r.maxi, root->val);
        return h;
    }
    int maxSumBST(TreeNode* root) {
        Helper h = dfs(root);
        return maxSum;
    }
};
