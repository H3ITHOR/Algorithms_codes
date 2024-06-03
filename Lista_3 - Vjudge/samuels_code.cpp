#include <iostream>

using namespace std;


// dictionary(hash table)
class HashTable {

private:

    // The idea is to reserve an space in memory
    // that if the pointer is pointing to it, it means
    // that the item was deleted
    string deleted = "";

    int size = 101;
    string supArray[101]; // An array that contains the strings
    string* mainArray[101]; // The main array (pointers to the supArray)
    int cnt = 0; // how many elements are in the dictionary

    void init() {

        for (size_t i = 0; i < size; i++){

            supArray[i] = ""; // setting all the elements to be empty strings
            mainArray[i] = nullptr; // nullptr means that nothing was inserted in the index
        }
    }

    int hash(string key) {

        int sum = 0;
        int index = 1;
        
        for (char i : key){
            
            sum += i * index;
            index++;
        }
        
        return (19 * sum) % 101;
    }

    // function that tries to insert an element and returns its index
    int tryInsert(const int& hashKey, const string item) {

        // checking for further indexes
        for (size_t i = 0; i < 20; i++){
        
            int furtherHashKey = (hashKey + (i * i) + (23 * i)) % 101;

            if (mainArray[furtherHashKey] != nullptr && mainArray[furtherHashKey] != &deleted){

                // if the element was already in the hash table
                if (*mainArray[furtherHashKey] == item)
                    return -1;
            }
        }

        // if there was no collisions
        if (mainArray[hashKey] == nullptr || mainArray[hashKey] == &deleted){

            supArray[hashKey] = item;
            mainArray[hashKey] = &supArray[hashKey];

            cnt++;

            return hashKey;
        }

        // if the element was already in the hash table
        if (*mainArray[hashKey] == item)
            return -1;

        // if there was collisions
        for (size_t i = 1; i < 20; i++){
            
            int newHashKey = (hashKey + (i * i) + (23 * i)) % 101;

            if (mainArray[newHashKey] == nullptr || mainArray[newHashKey] == &deleted){

                supArray[newHashKey] = item;
                mainArray[newHashKey] = &supArray[newHashKey];

                cnt++;

                return newHashKey;
            }

            // if the element was already in the hash table
            if (*mainArray[newHashKey] == item)
                return -1;
        }
        
        // returning -1 if we couldn't insert
        return -1;
    }   

    // function that tries to remove an element and returns its index
    int tryRemove(const int& hashKey, const string item) {

        // if no element was ever inserted in that index
        if (mainArray[hashKey] == nullptr)
            return -1;

        if (*mainArray[hashKey] == item){

            supArray[hashKey] = "";
            mainArray[hashKey] = &deleted;

            cnt--;

            return hashKey;
        }
        
        for (size_t i = 1; i < 20; i++){
            
            int newHashKey = (hashKey + (i * i) + (23 * i)) % 101;

            // if no element was ever inserted in that index
            if (mainArray[newHashKey] == nullptr)
                return -1;
            
            if (*mainArray[newHashKey] == item){
            
                supArray[newHashKey] = "";
                mainArray[newHashKey] = &deleted;

                cnt--;

                return newHashKey;
            }
        }
        
        // returning -1 if we couldn't remove
        return -1;
    }

public:

    HashTable() { init(); }
    ~HashTable() {}

    int insert(const string& item) {

        int hashKey = hash(item);
        return tryInsert(hashKey, item);
    }

    int remove(const string& item) {

        int hashKey = hash(item);
        return tryRemove(hashKey, item);
    }

    void print() {

        for (size_t i = 0; i < size; i++){
            
            if (mainArray[i] != nullptr && mainArray[i] != &deleted)
                std::cout << i << ":" << *mainArray[i] << '\n';
        }
    }

    int count() { return cnt; }
};


void separe(string main, string& str1, string& str2) {

    bool firstPart = true;

    for (char i : main){

        if (i == ':')
            firstPart = false;

        else
            (firstPart) ? str1 += i : str2 += i;
    }
    
}


int main() {

    int test_cases = 0;
    cin >> test_cases;

    for (size_t i = 0; i < test_cases; i++){

        auto* hashTable = new HashTable();

        int operations = 0;
        cin >> operations;

        for (size_t j = 0; j < operations; j++){
            
            string line = "";
            cin >> line;

            string action = "";
            string element = "";

            separe(line, action, element);

            if (action == "ADD")
                hashTable->insert(element);
            
            else if (action == "DEL")
                hashTable->remove(element);
        }

        int count = hashTable->count();

        std::cout << count << '\n';
        
        if (count > 0)
            hashTable->print();
    }
    

    return 0;
}