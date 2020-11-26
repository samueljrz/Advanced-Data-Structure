#ifndef hashtable_H
#define hashtable_H
#include <bits/stdc++.h>
using namespace std;

/* Definição do tipo da EntryType */
enum EntryType {ACTIVE, EMPTY};

template <typename Key, typename Value>
class HashTable {

public:
    explicit HashTable(int size = 1024); 
    bool contains(const Key &y) const;
    void makeEmpty();
    bool insert(const Key &y, const Value &v);
    bool remove(const Key &y);
    int size() const;
    bool search(const Key &y, Value &result);
    void print() const;

private:
    struct HashEntry { 
        std::pair<Key, Value> element;
        EntryType status;

        HashEntry(const Key &y = Key{ }, const Value &v = Value{ }, EntryType i = EMPTY)
            : element(make_pair(y,v)), status(i) { }
    };

    std::vector<HashEntry> table;

    /* número de elementos da tabela */
    int currentSize;

    /* Função de Hash */
    size_t hashFunction(const Key &y, int i) const;
};

/* Constructor */
template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(int tableSize):currentSize(0)
{
    table.resize(tableSize);
}

/* Retorna o tamanho da tabela */
template <typename Key, typename Value>
int HashTable<Key, Value>::size() const {
    return currentSize;
} 

/* Printa os elementos da tabela */
template <typename Key, typename Value>
void HashTable<Key, Value>::print() const {
	for(int i=0; i<table.size(); i++) {
		if(table[i].status == ACTIVE) {
			cout << i << " - " << table[i].element.first << ":" << table[i].element.second << endl;
		}
	}
}

/* Remove todos os elementos da tabela */
template <typename Key, typename Value>
void HashTable<Key, Value>::makeEmpty() {
	table.clear();
	currentSize = 0;
}

/* Função de HASH */  
template <typename Key, typename Value>
size_t HashTable<Key, Value>::hashFunction(const Key &x, int i) const {
    std::hash<Key> hf;
    return ((hf(x)%table.size()) + i)%table.size();
} 

/* Verifica se uma chave y esta na tabela */
template <typename Key, typename Value>
bool HashTable<Key, Value>::contains(const Key &y) const {
    int i = 0;
    while(i < table.size()) {
        size_t elemento = hashFunction(y, i);
        if((table[elemento].element.first == y) && (table[elemento].status == ACTIVE)) {
            return true;
        }
        i++;
    }
    return false;
}

/* Busca uma chave y na tabela e retorna o respectivo valor associado a ela */
template <typename Key, typename Value>
bool HashTable<Key, Value>::search(const Key &y, Value &result) {
	int i = 0;
    while(i < table.size()) {
        size_t elemento = hashFunction(y, i);
        if((table[elemento].element.first == y) && (table[elemento].status == ACTIVE)) {
        	result = table[elemento].element.second;
            return true;
        }
        i++;
    }
    return false;
}

/* Remove um elemento unico y se estiver na tabela */
template <typename Key, typename Value>
bool HashTable<Key, Value>::remove(const Key &y) {
	int i = 0;
    while(i < table.size()) {
        size_t elemento = hashFunction(y, i);
        if((table[elemento].element.first == y) && (table[elemento].status == ACTIVE)) {
        	table[elemento].status = EMPTY;
            return true;
        }
        i++;
    }
    return false;
}

/* Insere um elemento unico na tabela */
template <typename Key, typename Value>
bool HashTable<Key, Value>::insert(const Key &y, const Value &v) {
    int i = 0;
    if(contains(y)) {
        return false;
    }
    while (i < table.size()) {
        size_t elemento = hashFunction(y, i);
        if(table[elemento].status == EMPTY) {
            table[elemento].element.first = y;
            table[elemento].element.second = v;
            table[elemento].status = ACTIVE;
            currentSize++;
            return true;
        }
    	i++;
    }
}
#endif