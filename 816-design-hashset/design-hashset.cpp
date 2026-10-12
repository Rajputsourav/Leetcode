class MyHashSet {
private:
    bool arr[1000001] = {};

public:
    MyHashSet() {
    }

    void add(int key) {
        arr[key] = true;
    }

    void remove(int key) {
        arr[key] = false;
    }

    bool contains(int key) {
        return arr[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */