#include<bits/stdc++.h>
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

bool HashTable::isEmpty() const {
    int sum = 0;
    for (int i = 0; i < hashgroup; i++) {
        sum += table[i].size();
    }
    return sum == 0;
}

int HashTable::hashFunction(int key) {
    return key % hashgroup;
}

void HashTable::insertItem(int key, string value) {
    int hashvalue = hashFunction(key);
    auto& cell = table[hashvalue];
    auto itr = begin(cell);
    bool keyExists = false;

    for (; itr != cell.end(); itr++) {
        if (itr->first == key) {
            keyExists = true;
            itr->second = value;
            break;
        }
    }

    if (!keyExists) {
        cell.emplace_back(key, value);
    }
}

void HashTable::removeItem(int key) {
    int hashvalue = hashFunction(key);
    auto& cell = table[hashvalue];
    auto itr = begin(cell);

    for (; itr != cell.end(); itr++) {
        if (itr->first == key) {
            itr = cell.erase(itr);
            break;
        }
    }
}

string HashTable::searchTable(int key) {
    int hashvalue = hashFunction(key);
    auto& cell = table[hashvalue];
    auto itr = begin(cell);

    for (; itr != cell.end(); itr++) {
        if (itr->first == key) {
            return itr->second;
        }
    }
    return "Not Found";
}

void HashTable::printTable() {
    for (int i = 0; i < hashgroup; i++) {
        if (table[i].size() == 0) continue;
        auto itr = table[i].begin();
        for (; itr != table[i].end(); itr++) {
            cout << itr->first << " -> " << itr->second << endl;
        }
    }
}

int main() {
    HashTable ht;
    cout << "Is the table empty? " << (ht.isEmpty() ? "Yes" : "No") << endl;

    ht.insertItem(1, "one");
    ht.insertItem(2, "two");
    ht.insertItem(12, "twelve");
    
    cout << "After inserting items:" << endl;
    ht.printTable();

    cout << "Searching for key 2: " << ht.searchTable(2) << endl;
    cout << "Searching for key 5: " << ht.searchTable(5) << endl;

    ht.removeItem(2);
    cout << "After removing key 2:" << endl;
    ht.printTable();

    return 0;
}