class Solution {
public:
    int preIndex = 0;
    unordered_map<int, int> mp;

    TreeNode* build(int left, int right, vector<int>& preorder) {
        if (left > right) {
            return nullptr;
        }

        int rootValue = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(rootValue);

        int mid = mp[rootValue];

        root->left = build(left, mid - 1, preorder);
        root->right = build(mid + 1, right, preorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(0, inorder.size() - 1, preorder);
    }
};