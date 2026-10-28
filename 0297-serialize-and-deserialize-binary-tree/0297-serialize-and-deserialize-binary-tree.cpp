class Codec {
public:

// Serialize the tree into a string
string serialize(TreeNode* root) {
    if (root == nullptr)
        return "";

    string result = "";
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            result += "#,";
            continue;
        }

        result += to_string(node->val) + ",";

        q.push(node->left);
        q.push(node->right);
    }

    return result;
}

// Deserialize the string back into a tree
TreeNode* deserialize(string data) {
    if (data.empty())
        return nullptr;

    stringstream ss(data);
    string value;

    getline(ss, value, ',');

    TreeNode* root = new TreeNode(stoi(value));

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        // Read left child
        if (!getline(ss, value, ','))
            break;

        if (value != "#") {
            node->left = new TreeNode(stoi(value));
            q.push(node->left);
        }

        // Read right child
        if (!getline(ss, value, ','))
            break;

        if (value != "#") {
            node->right = new TreeNode(stoi(value));
            q.push(node->right);
        }
    }

    return root;
}

};
