#include <iostream>
#include <list>
#include <cstring>

using namespace std;

// Hashtable to implement 905, jinny;

class HashTable {
    private:
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups]; // List 1, index 0, list 2, index 1...

    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const{
    int sum{};
    for (int i{}; i < hashGroups; i++){
        sum += table[i].size();
    }

    if (!sum){
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key){
    return key % hashGroups; //key: 905, int return, this function will split out 5
}

void HashTable::insertItem(int key, string value){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++){
        if (bItr->first == key){
            keyExists = true;
            bItr->second = value;
            cout << "[Warning] key exists, value occupied" << endl;
        }
    }
}