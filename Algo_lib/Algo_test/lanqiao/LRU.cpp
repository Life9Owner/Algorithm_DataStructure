#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;

    Node() : prev(NULL), next(NULL) {}
    Node(int key, int value) : key(key), value(value), prev(NULL), next(NULL) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mmap.find(key) == mmap.end())
            return -1;
        move_to_head(key);
        return mmap[key]->value;
    }

    void put(int key, int value) {
        if (size >= capacity) {
            delete_last();
        }
        Node* new_one = new Node(key, value);
        new_one->prev = head;
        new_one->next = head->next;
        head->next = new_one;
        head->next->prev = new_one;
        mmap.insert({ key, new_one });
        size++;
    }

    int size, capacity;

    void move_to_head(int key) {
        Node* new_head = mmap[key];
        Node* before = new_head->prev;
        Node* after = new_head->next;
        before->next = after;
        after->prev = before;

        new_head->prev = head;
        new_head->next = head->next;
        head->next = new_head;
        head->next->prev = new_head;
        mmap.insert({ key, new_head });
    }

    void delete_last() {
        size--;
        Node* del = tail->prev;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;

        mmap.erase(del->key);
        delete del;
    }

    unordered_map<int, Node*> mmap;
    Node* head;
    Node* tail;
};

int main() {
    // Testing the LRUCache class
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;     // Output: 1
    cache.put(3, 3);
    cout << cache.get(2) << endl;     // Output: -1
    cache.put(4, 4);
    cout << cache.get(1) << endl;     // Output: -1
    cout << cache.get(3) << endl;     // Output: 3
    cout << cache.get(4) << endl;     // Output: 4

    return 0;
}
