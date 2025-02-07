#include <bits/stdc++.h>
using namespace std;

class HashTable {
private:
    static const int hashgroup = 10;
    list<pair<int, string>> table[hashgroup];

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

// Check if table is empty
bool HashTable::isEmpty() const {
    int sum = 0;
    for (int i = 0; i < hashgroup; i++) {
        sum += table[i].size();
    }
    return sum == 0;
}

// Hash function to get index
int HashTable::hashFunction(int key) {
    return key % hashgroup;
}

// Insert item into hash table
void HashTable::insertItem(int key, string value) {
    int hashvalue = hashFunction(key);
    auto& cell = table[hashvalue];
    bool keyExists = false;

    // Check if key already exists
    for (auto& itr : cell) {
        if (itr.first == key) {
            keyExists = true;
            itr.second = value;
            break;
        }
    }

    // If key doesn't exist, insert new key-value pair
    if (!keyExists) {
        cell.emplace_back(key, value);
    }
}

// Remove item from hash table
void HashTable::removeItem(int key) {
    int hashvalue = hashFunction(key);
    auto& cell = table[hashvalue];

    for (auto itr = cell.begin(); itr != cell.end(); ++itr) {
        if (itr->first == key) {
            cell.erase(itr);
            break;
        }
    }
}

// Search item in hash table
string HashTable::searchTable(int key) {
    int hashvalue = hashFunction(key);
    auto& cell = table[hashvalue];

    for (auto& itr : cell) {
        if (itr.first == key) {
            return itr.second;
        }
    }
    return "Not Found"; // If key not found
}

// Print all elements in the hash table
void HashTable::printTable() {
    bool tableEmpty = true;
    for (int i = 0; i < hashgroup; i++) {
        if (!table[i].empty()) {
            tableEmpty = false;
            for (auto& itr : table[i]) {
                cout << itr.first << " -> " << itr.second << endl;
            }
        }
    }
    if (tableEmpty) {
        cout << "Table is empty." << endl;
    }
}

int main() {
    HashTable ht;
    cout << (ht.isEmpty() ? "Table is empty" : "Table is not empty") << endl;
    ht.insertItem(1, "one");
    ht.insertItem(11, "eleven");
    ht.insertItem(21, "twenty-one");
    cout << "Hash Table after insertions: " << endl;
    ht.printTable();
    cout << "Search for key 11: " << ht.searchTable(11) << endl;
    cout << "Search for key 30: " << ht.searchTable(30) << endl;
    ht.removeItem(11);
    cout << "Hash Table after removal: " << endl;
    ht.printTable();

    return 0;
}