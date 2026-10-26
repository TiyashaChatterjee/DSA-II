class Node{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        
        Node(int key1, int value1){
            key=key1;
            value=value1;
            next = nullptr;
            prev=nullptr;
        }
};

class LRUCache {
    private:
        int cap;
        unordered_map<int, Node*>mpp;
        Node* left;
        Node* right;

        void insert(Node* node){
            Node* prev = right->prev;
            node->prev=prev;
            node->next=right;
            right->prev=node;
            prev->next=node;
        }
        void remove(Node* node){
            Node* Next = node->next;
            Node* prev = node->prev;
            prev->next = Next;
            Next->prev=prev;
        }
public:
    LRUCache(int capacity) {
        cap=capacity;
        mpp.clear();
        left = new Node(0,0);
        right = new Node (0,0);
        left->next=right;
        right->prev=left;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* newNode = mpp[key];
            remove(newNode);
            insert(newNode);
            return newNode->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
       if(mpp.find(key)!=mpp.end()){
            remove(mpp[key]);
            mpp.erase(key);
            delete(mpp[key]);
       }
       Node* newNode = new Node(key, value);
       mpp[key]=newNode;
       insert(newNode);

       if(mpp.size()>cap){
            Node* lru = left->next;
            remove(lru);
            mpp.erase(lru->key);
            delete(lru);
       }
    }
};
