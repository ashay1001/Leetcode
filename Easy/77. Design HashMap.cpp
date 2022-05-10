class MyHashMap {
public:
    int data[1000001];
    MyHashMap() {
        memset(data, -1, sizeof(data));
    }
    void put(int key, int val) {
        data[key] = val;
    }
    int get(int key) {
        return data[key];
    }
    void remove(int key) {
        data[key] = -1;
    }
};