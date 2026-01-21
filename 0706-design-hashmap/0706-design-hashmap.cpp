class MyHashMap {
public:
    unordered_map<int , int>MyHashMapu;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
          if (MyHashMapu.find(key) != MyHashMapu.end()) {
        MyHashMapu[key] = value;
    } 
        else {
        MyHashMapu.insert({key, value});
        }
    }
    
    int get(int key) {
        if (MyHashMapu.find(key) != MyHashMapu.end()) {
        return MyHashMapu[key];
    } 
        return -1;
    }
    
    void remove(int key) {
    MyHashMapu.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */