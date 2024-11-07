#include<bits/stdc++.h>
using namespace std;

class HashTable {
private:
    static const int hashgroup = 10;  // Number of buckets in hash table
    list<pair<int, string>> table[hashgroup];  // Array of lists for chaining

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

// Check if hash table is empty
bool HashTable::isEmpty() const {
    int sum = 0;
    for (int i = 0; i < hashgroup; i++) {
        sum += table[i].size();  // Sum up the size of all lists
    }
    return sum == 0;  // If total size is 0, the table is empty
}

// Hash function to calculate the index
int HashTable::hashFunction(int key) {
    return key % hashgroup;  // Simple modulo hash function
}

// Insert key-value pair into the hash table
void HashTable::insertItem(int key, string value) {
    int hashvalue = hashFunction(key);  // Get the hash value
    auto& cell = table[hashvalue];  // Get the list at the hashed index
    auto itr = begin(cell);
    bool keyExists = false;

    // Traverse the list to check if the key already exists
    for (; itr != cell.end(); itr++) {
        if (itr->first == key) {
            keyExists = true;
            itr->second = value;  // Update the value if key exists
            break;
        }
    }

    // If the key doesn't exist, add a new pair
    if (!keyExists) {
        cell.emplace_back(key, value);  // Insert new key-value pair
    }
}

// Remove key-value pair from the hash table
void HashTable::removeItem(int key) {
    int hashvalue = hashFunction(key);  // Get the hash value
    auto& cell = table[hashvalue];  // Get the list at the hashed index
    auto itr = begin(cell);

    // Traverse the list to find and remove the pair with the matching key
    for (; itr != cell.end(); itr++) {
        if (itr->first == key) {
            itr = cell.erase(itr);  // Erase the key-value pair
            break;
        }
    }
}

// Search for a key in the hash table and return the corresponding value
string HashTable::searchTable(int key) {
    int hashvalue = hashFunction(key);  // Get the hash value
    auto& cell = table[hashvalue];  // Get the list at the hashed index
    auto itr = begin(cell);

    // Traverse the list to find the value for the given key
    for (; itr != cell.end(); itr++) {
        if (itr->first == key) {
            return itr->second;  // Return the corresponding value
        }
    }
    return "Not Found";  // Return "Not Found" if key doesn't exist
}

// Print all key-value pairs in the hash table
void HashTable::printTable() {
    for (int i = 0; i < hashgroup; i++) {
        if (table[i].size() == 0) continue;  // Skip empty lists
        auto itr = table[i].begin();
        for (; itr != table[i].end(); itr++) {
            cout << itr->first << " -> " << itr->second << endl;  // Print key-value pair
        }
    }
}

int main() {
    HashTable ht;  // Create a hash table object
    cout << "Is the table empty? " << (ht.isEmpty() ? "Yes" : "No") << endl;

    ht.insertItem(1, "one");  // Insert key-value pair (1, "one")
    ht.insertItem(2, "two");  // Insert key-value pair (2, "two")
    ht.insertItem(12, "twelve");  // Insert key-value pair (12, "twelve")
    
    cout << "After inserting items:" << endl;
    ht.printTable();  // Print the hash table

    cout << "Searching for key 2: " << ht.searchTable(2) << endl;  // Search for key 2
    cout << "Searching for key 5: " << ht.searchTable(5) << endl;  // Search for key 5 (not in table)

    ht.removeItem(2);  // Remove item with key 2
    cout << "After removing key 2:" << endl;
    ht.printTable();  // Print the hash table again

    return 0;
}