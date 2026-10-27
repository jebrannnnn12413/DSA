class Solution {
public:

    TreeNode* buildTreeHelper(
        vector<int>& inorder,
        vector<int>& postorder,
        int& postIndex,
        int left,
        int right
    )
    {
        // Base case: no elements left
        if (left > right)
        {
            return NULL;
        }

        // Step 1: Get the root from postorder
        int rootValue = postorder[postIndex];
        postIndex--;

        TreeNode* root = new TreeNode(rootValue);

        // Step 2: Find the root in inorder
        int inorderIndex = left;

        while (inorder[inorderIndex] != rootValue)
        {
            inorderIndex++;
        }

        // Step 3: Build the right subtree first
        root->right = buildTreeHelper(
            inorder,
            postorder,
            postIndex,
            inorderIndex + 1,
            right
        );

        // Step 4: Build the left subtree
        root->left = buildTreeHelper(
            inorder,
            postorder,
            postIndex,
            left,
            inorderIndex - 1
        );

        // Step 5: Return the constructed subtree
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int postIndex = postorder.size() - 1;

        return buildTreeHelper(
            inorder,
            postorder,
            postIndex,
            0,
            inorder.size() - 1
        );
    }
};