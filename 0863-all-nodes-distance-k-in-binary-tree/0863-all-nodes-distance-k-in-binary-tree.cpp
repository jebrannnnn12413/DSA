class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> parent;

    void makeParent(TreeNode* root) {
        if (root == NULL)
            return;

        if (root->left) {
            parent[root->left] = root;
            makeParent(root->left);
        }

        if (root->right) {
            parent[root->right] = root;
            makeParent(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // Step 1: Create parent mapping
        makeParent(root);

        // Step 2: BFS
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int distance = 0;

        while (!q.empty()) {

            // We have reached distance k
            if (distance == k)
                break;

            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Left
                if (node->left &&
                    visited.find(node->left) == visited.end()) {

                    q.push(node->left);
                    visited.insert(node->left);
                }

                // Right
                if (node->right &&
                    visited.find(node->right) == visited.end()) {

                    q.push(node->right);
                    visited.insert(node->right);
                }

                // Parent
                if (parent.find(node) != parent.end()) {

                    TreeNode* p = parent[node];

                    if (visited.find(p) == visited.end()) {
                        q.push(p);
                        visited.insert(p);
                    }
                }
            }

            distance++;
        }

        // Step 3: Everything in queue is distance k
        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};