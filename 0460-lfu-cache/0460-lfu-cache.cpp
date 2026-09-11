class LFUCache {
public:
    struct Node {
        int key, value, freq;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            next = NULL;
            prev = NULL;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, list<Node*>> freqList;
    unordered_map<int, list<Node*>::iterator> pos;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void update(Node* node) {
        int f = node->freq;

        freqList[f].erase(pos[node->key]);

        if (freqList[f].empty() && minFreq == f)
            minFreq++;

        node->freq++;

        freqList[node->freq].push_front(node);
        pos[node->key] = freqList[node->freq].begin();
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node* node = keyNode[key];

        update(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];

            node->value = value;
            update(node);

            return;
        }

        if (keyNode.size() == capacity) {
            Node* lfu = freqList[minFreq].back();

            keyNode.erase(lfu->key);
            pos.erase(lfu->key);
            freqList[minFreq].pop_back();

            delete lfu;
        }

        Node* node = new Node(key, value);

        keyNode[key] = node;
        freqList[1].push_front(node);
        pos[key] = freqList[1].begin();

        minFreq = 1;
    }
};