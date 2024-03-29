class LRUCache {
public:

    class Node
    {
        public:
            int key;
            int value;
            Node* next;
            Node* prev;
            Node(int k, int v)
            {
                key = k;
                value = v;
            }            
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
    unordered_map<int,Node*>mp;

    LRUCache(int capacity) 
    {  
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) 
    {
        if(mp.find(key) != mp.end())
        {
            Node* res = mp[key];
            int val = res->value;
            mp.erase(key);
            deleteNode(res);
            addNode(res);
            mp[key] = head->next;
            return val;
        }  
        return -1;
    }

    void deleteNode(Node* nodetodelete)
    {
        Node* delnodeprev = nodetodelete->prev;
        Node* delnodenext = nodetodelete->next;

        delnodeprev->next = delnodenext;
        delnodenext->prev = delnodeprev;
    }

    void addNode(Node* newnode)
    {
        Node* temp = head->next;

        head->next = newnode;
        newnode->prev = head;
        newnode->next = temp;
        temp->prev = newnode;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key) != mp.end())
        {
            Node* node = mp[key];
            deleteNode(node);
            mp.erase(key);
        }

        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */