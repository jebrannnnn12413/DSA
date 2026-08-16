class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        // 1. Create copied nodes and insert them after original nodes
        Node* curr = head;

        while (curr) {
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // 2. Set random pointers of copied nodes
        curr = head;

        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        // 3. Separate original and copied lists
        curr = head;
        Node* copyHead = head->next;

        while (curr) {
            Node* copy = curr->next;

            curr->next = copy->next;

            if (copy->next)
                copy->next = copy->next->next;

            curr = curr->next;
        }

        return copyHead;
    }
};