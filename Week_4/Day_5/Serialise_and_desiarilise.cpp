/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // ---------- Serialize ----------
    void preorder(TreeNode* root, string &s) {
        if (!root) return;

        s += to_string(root->val) + " ";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        preorder(root, s);
        return s;
    }

    // ---------- Deserialize ----------
    TreeNode* buildBST(vector<int> &vals, int &i, int minV, int maxV) {
        if (i >= vals.size()) return nullptr;

        int val = vals[i];
        if (val < minV || val > maxV) return nullptr;

        TreeNode* node = new TreeNode(val);
        i++;

        node->left = buildBST(vals, i, minV, val);
        node->right = buildBST(vals, i, val, maxV);

        return node;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<int> vals;
        stringstream ss(data);
        int num;

        while (ss >> num) {
            vals.push_back(num);
        }

        int i = 0;
        return buildBST(vals, i, INT_MIN, INT_MAX);
    }
};
