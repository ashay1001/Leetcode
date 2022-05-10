class MyHashSet {
public:
    int arr[10000001];
    MyHashSet() {
        memset(arr, -1, sizeof(arr));
    }
    
    void add(int key) {
     arr[key] = key;   
    }
    
    void remove(int key) {
        arr[key] = -1;
    }
    
    bool contains(int key) {
        if(arr[key] == -1)
            return false;
        else
            return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */