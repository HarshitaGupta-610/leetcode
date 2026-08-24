struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    // ye ek Node hai, jisme key-value store hoga, aur do pointers honge
    // ek prev (peeche wale node ka address) aur next (aage wale node ka address)
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity; // jitni capacity di hai, use yaad rakh lo (variable me store karo)  
        head = new Node(-1, -1); // ek fake/dummy node banaya jo list ke sabse aage rahega
        tail = new Node(-1, -1); // ek fake/dummy node banaya jo list ke sabse peeche rahega
        // -1,-1 isliye diya kyunki ye dummy nodes hain, inme real data nahi rakhna   
        head->next = tail; // head ke aage tail hai (abhi list khali hai)
        tail->prev = head; // tail ke peeche head hai
        // matlab abhi list aisi dikhti hai: head <-> tail (koi real data nahi)
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            // agar key hashmap me nahi mili, matlab cache me hai hi nahi
            return -1; // to -1 return karo (not found)
        }
        
        Node* node = cache[key]; // hashmap se us key ka node nikal liya (O(1) me mil gaya)
        
        // key mil gayi hai, to isko "abhi abhi use kiya" mark karna hai
        removeNode(node);   // pehle node ko uski current position se hata do
        insertAtFront(node); // fir usko sabse aage (most recently used) laga do
        
        return node->value; // aur uski value return kar do
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // agar key already cache me maujood hai
            Node* node = cache[key]; // uska node nikalo
            node->value = value;     // value update kar do naye value se
            
            // isko bhi "abhi use hua" mark karna hai, isliye front pe le jao
            removeNode(node);
            insertAtFront(node);
            return; // kaam ho gaya, function se bahar nikal jao
        }
        
        // agar yaha aaye hain, matlab ye ek NAYI key hai jo cache me nahi thi
        
        if ((int)cache.size() == cap) {
            // agar cache already full hai (capacity jitni items already hain)
            
            Node* lru = tail->prev; 
            // tail se just pehle wala node hi sabse "least recently used" hota hai
            // kyunki sabse recent wale hamesha front (head ke paas) me hote hain
            
            removeNode(lru);        // us LRU node ko list se nikaal do
            cache.erase(lru->key);  // hashmap se bhi uski entry mita do
            delete lru;             // aur uski memory free kar do (taaki memory leak na ho)
        }
        
        // ab naya node banake insert karna hai
        Node* newNode = new Node(key, value); // naya node banaya with given key-value
        insertAtFront(newNode);               // usko list ke front me daal do (most recent)
        cache[key] = newNode;                 // aur hashmap me bhi entry bana do: key -> node address
    }

private:
    int cap; // cache ki max capacity (kitne items rakh sakte hain)
    Node* head; // dummy node, list ka sabse start wala marker
    Node* tail; // dummy node, list ka sabse end wala marker
    unordered_map<int, Node*> cache; // key se seedha node ka address milega (fast lookup ke liye)
    
    void removeNode(Node* node) {
        // node ko uske current position se list se nikalna hai (unlink karna hai)
        
        node->prev->next = node->next; 
        // node ke pehle wale ka "next" ab node ke baad wale ko point karega
        // matlab node ko "jump" kar diya
        
        node->next->prev = node->prev;
        // node ke baad wale ka "prev" ab node ke pehle wale ko point karega
        // ab dono taraf se node ka naam-o-nishaan list se hat gaya
        // (lekin node khud memory me abhi bhi hai, bas list se disconnect hai)
    }
    
    void insertAtFront(Node* node) {
        // node ko head ke turant baad insert karna hai (matlab "most recently used" position)
        
        node->next = head->next; 
        // naye node ka next = jo pehle head ke baad wala tha (purana pehla real node)
        
        node->prev = head;       
        // naye node ka prev = head (kyunki ye ab sabse aage lagne wala hai)
        
        head->next->prev = node; 
        // jo pehle head ke turant baad wala node tha, uska prev ab naye node ko point karega
        
        head->next = node;       
        // aur head ka next ab is naye node ko point karega
        // ab node successfully head ke turant baad "insert" ho gaya
    }
};