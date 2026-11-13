class Node{
    public:
    int key,value;
    Node *next;
    Node *prev;

    Node(int k,int v){
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    unordered_map<int,Node*>mp;
    Node *head;
    Node *tail;
    int cap;

    void deleteNode(Node *node){
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insertHead(Node *node){
        Node *nextNode = head->next;

        node->next = nextNode;
        node->prev = head;

        head->next = node;
        nextNode->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node *node = mp[key];

        deleteNode(node);
        insertHead(node);

        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node *node = mp[key];
            node->value = value;

            deleteNode(node);
            insertHead(node);

            return;
        }
        if(mp.size() == cap){
            Node *lruNode = tail->prev;

            mp.erase(lruNode->key);
            deleteNode(lruNode);

            delete lruNode;
        }
        Node *newNode = new Node(key,value);

        mp[key] = newNode;
        insertHead(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */