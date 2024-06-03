#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>

using namespace std;

// minha implementação de hash_table com linear probing

template <typename K, typename V>
class HashNode {
public:
    K key;
    V value;
    HashNode() {}
    HashNode(K key, V value) : key(key), value(value) {}
};

template <typename K, typename V>
class MyHashTable {
    HashNode<K, V> **arr;
    int size;
    int count;

public:
    MyHashTable(int s) {
        count = 0;
        size = s;
        arr = new HashNode<K, V>*[size];

        for (int i = 0; i < size; i++) {
            arr[i] = nullptr;
        }
    }

    int hashIt(const string &key) {
        int h = 0; // Inicializa h como 0, que será usado para acumular o valor de h(key)
        for (int i = 0; i < key.length(); i++) {
            h += (key[i]) * (i + 1); // Converte o caractere para seu valor ASCII e multiplica pelo índice (i+1)
        }
        h *= 19; // Multiplica o acumulado por 19
        return abs(h) % 101; // Retorna h mod 101
    }


    V getItem(K key) {
        if (count == 0) {
            // throw runtime_error();
            return;
        }
        int hashIndex = hashIt(key);
        int temp = hashIndex;
        while (arr[hashIndex] != nullptr) {
            if (arr[hashIndex]->key == key) {
                return arr[hashIndex]->value;
            }
            hashIndex = (hashIndex + 1) % size;
            if (hashIndex == temp) {
                break;
            }
        }
        // throw runtime_error();
        return;
    }

void insertItem(K key, V value) {
    if (count == size) {
        return;
    }
    
    int hashIndex = hashIt(key);
    int initialIndex = hashIndex;
    int j = 0;
    int examinedEntries = 0;
    bool isThere;

    while (arr[hashIndex] != nullptr && examinedEntries < 20) {
        if (arr[hashIndex]->key == key) {
            // Chave já existe, não é necessário inserir novamente
            return;
        }
        // Resolve colisão utilizando quadratic probing
        hashIndex = (initialIndex + j*j + 23*j) % size;
        j++;
        examinedEntries++;
        // Verifica se voltou ao índice inicial, o que indica que a tabela está cheia
        // if (hashIndex == initialIndex) {
        //     return;
        // }
    }

    // Insere na primeira posição disponível
    if (arr[hashIndex] == nullptr) {
        arr[hashIndex] = new HashNode<K, V>(key, value);
        count++;
    }
}



    void deleteItem(K key) {
        if (count == 0) {
            return;
        }
        int hashIndex = hashIt(key);
        int temp = hashIndex;
        while (arr[hashIndex] != nullptr) {
            if (arr[hashIndex]->key == key) {
                delete arr[hashIndex];
                arr[hashIndex] = nullptr;
                count--;
                return;
            }
            hashIndex = (hashIndex + 1) % size;
            if (hashIndex == temp) {
                return;
            }
        }
    }

    void displayAll() {
        cout << count << " " << "\n";
        for (int i = 0; i < size; i++) {
            if (arr[i] != nullptr) {
                cout <<  i << ":" << arr[i]->value << " " << "\n";
            }
        }
    }

    ~MyHashTable() {
        for (int i = 0; i < size; i++) {
            if (arr[i] != nullptr) {
                delete arr[i];
            }
        }
        delete[] arr;
    }
};

template <typename K, typename V>
class Dictionary {
    MyHashTable<K, V> *hashTable;

public:
    Dictionary(int size) {
        hashTable = new MyHashTable<K, V>(size);
    }

    void add(K key, V value) {
        hashTable->insertItem(key, value);
    }

    V get(K key) {
        return hashTable->getItem(key);
    }

    void remove(K key) {
        hashTable->deleteItem(key);
    }

    void display() {
        hashTable->displayAll();
    }

    ~Dictionary() {
        delete hashTable;
    }
};


int main() {
    int test_cases;
    int operations;
    string inputs;
    string operation;
    string value;

    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        Dictionary<string, string> dict(101);
        // Lê o número de operações para o caso de teste atual
        cin >> operations;

        // Processa as operações para o caso de teste atual
        for (int j = 0; j < operations; j++) {
            cin >> inputs;
            operation = inputs.substr(0, 3);
            value = inputs.substr(4);

            if (operation == "ADD") {
                dict.add(value, value);
            } else if (operation == "DEL") {
                dict.remove(value);
            }
        }
        dict.display();
    }

    return 0;
}
