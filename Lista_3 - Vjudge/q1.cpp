#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Minha implementação de hash_table com quadratic probing
template <typename K, typename V>
class HashNode {
public:
    K key;
    V value;
    bool isDeleted;
    HashNode() : isDeleted(false) {}
    HashNode(K key, V value) : key(key), value(value), isDeleted(false) {}
};

template <typename K, typename V>
class MyHashTable {
    HashNode<K, V> **arr;
    int size;
    int count;

public:
    MyHashTable(int s) { // Método construtor
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
        }
        int hashIndex = hashIt(key);
        for (int j = 0; j < 20; j++) {
            int tempIndex = (hashIndex + j * j + 23 * j) % size;
            if (arr[tempIndex] != nullptr && !arr[tempIndex]->isDeleted && arr[tempIndex]->key == key) {
                return arr[tempIndex]->value;
            }
            if (arr[tempIndex] == nullptr) {
                break; // Parar a busca se encontrar uma posição vazia
            }
        }
    }

    void insertItem(K key, V value) {
        if (count == size) {
            return;
        }

        // Primeiramente, verifica se a chave já existe na tabela
        for (int i = 0; i < size; i++) {
            if (arr[i] != nullptr && arr[i]->key == key && !arr[i]->isDeleted) {
                // Chave já existe, não é necessário inserir novamente
                return;
            }
        }

        int hashIndex = hashIt(key);
        int initialIndex = hashIndex;
        int j = 0;
        int examinedEntries = 0;

        // Tenta inserir na primeira posição disponível ou marcada como deletada
        while ((arr[hashIndex] != nullptr && !arr[hashIndex]->isDeleted) && examinedEntries < 20) {
            // Resolve colisão utilizando quadratic probing
            hashIndex = (initialIndex + j*j + 23*j) % size;
            j++;
            examinedEntries++;
        }

        // Insere na primeira posição disponível ou marcada como deletada
        if (arr[hashIndex] == nullptr || arr[hashIndex]->isDeleted) {
            if (arr[hashIndex] == nullptr) {
                arr[hashIndex] = new HashNode<K, V>(key, value);
            } else {
                arr[hashIndex]->key = key;
                arr[hashIndex]->value = value;
                arr[hashIndex]->isDeleted = false;
            }
            count++;
        }
    }

    void deleteItem(K key) {
        if (count == 0) {
            return;
        }
        int hashIndex = hashIt(key);
        for (int j = 0; j < 20; j++) {
            int tempIndex = (hashIndex + j * j + 23 * j) % size;
            if (arr[tempIndex] != nullptr && !arr[tempIndex]->isDeleted && arr[tempIndex]->key == key) {
                arr[tempIndex]->isDeleted = true;
                count--;
                return;
            }
            if (arr[tempIndex] == nullptr) {
                return; // Parar a busca se encontrar uma posição vazia
            }
        }
    }

    void displayAll() {
        cout << count << "\n";
        for (int i = 0; i < size; i++) {
            if (arr[i] != nullptr && !arr[i]->isDeleted) {
                cout << i << ":" << arr[i]->value << "\n";
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
