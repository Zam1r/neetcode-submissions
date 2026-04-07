class DynamicArray {
public:
    std::vector<int> store;
    DynamicArray(int capacity) {
        store.reserve(capacity);
    }

    int get(int i) {
        return store[i];
    }

    void set(int i, int n) {
        store[i] = n;
    }

    void pushback(int n) {
        store.push_back(n);
    }

    int popback() {
        int last = store.back();
        store.pop_back();
        return last;
    }

    void resize() {
        int capacity = store.capacity();
        store.reserve(capacity * 2);
    }

    int getSize() {
        return store.size();
    }

    int getCapacity() {
        return store.capacity();
    }
};
