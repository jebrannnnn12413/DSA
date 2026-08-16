class BrowserHistory {
public:
    class Node {
    public:
        string data;
        Node* next;
        Node* prev;

        Node(string data) {
            this->data = data;
            next = NULL;
            prev = NULL;
        }
    };
    Node* curr;
    BrowserHistory(string homepage) { curr = new Node(homepage); }

    void visit(string url) {
        Node* newnode = new Node(url);
        curr->next = newnode;
        newnode->prev = curr;

        curr = newnode;
    }

    string back(int steps) {
        while (steps > 0 && curr->prev != NULL) {
            curr = curr->prev;
            steps--;
        }
        return curr->data;
    }

    string forward(int steps) {
        while (steps > 0 && curr->next != NULL) {
            curr = curr->next;
            steps--;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */