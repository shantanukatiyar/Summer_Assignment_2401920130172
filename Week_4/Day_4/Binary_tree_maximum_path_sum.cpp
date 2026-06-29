/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftGain = max(0, dfs(root->left));
        int rightGain = max(0, dfs(root->right));

        // Maximum path passing through current node
        ans = max(ans, leftGain + rightGain + root->val);

        // Return maximum gain to parent
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
