
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int capacity;

    // Front = most recently used
    // Back = least recently used
    list<pair<int, int>> cache;

    // Key -> iterator pointing to its list entry
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        auto it = mp.find(key);

        if (it == mp.end()) {
            return -1;
        }

        // Move the accessed entry to the front
        cache.splice(cache.begin(), cache, it->second);

        return it->second->second;
    }

    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }

        auto it = mp.find(key);

        if (it != mp.end()) {
            // Update existing value
            it->second->second = value;

            // Mark it as most recently used
            cache.splice(cache.begin(), cache, it->second);
            return;
        }

        // Remove least recently used entry if full
        if (cache.size() == capacity) {
            int lruKey = cache.back().first;
            cache.pop_back();
            mp.erase(lruKey);
        }

        // Insert new entry at the front
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

int main() {
    LRUCache lru(2);

    lru.put(1, 10);
    lru.put(2, 20);

    cout << lru.get(1) << endl;  // 10

    lru.put(3, 30);              // Evicts key 2

    cout << lru.get(2) << endl;  // -1
    cout << lru.get(3) << endl;  // 30
    cout << lru.get(1) << endl;  // 10

    return 0;
}
