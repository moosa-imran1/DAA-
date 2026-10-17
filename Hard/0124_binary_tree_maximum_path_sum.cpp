class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxGain(root, ans);
        return ans;
    }

private:
    int maxGain(TreeNode* node, int& ans) {
        if (!node) return 0;

        int left = max(0, maxGain(node->left, ans));
        int right = max(0, maxGain(node->right, ans));

        ans = max(ans, node->val + left + right);

        return node->val + max(left, right);
    }
};
