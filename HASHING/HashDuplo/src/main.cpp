#include <bits/stdc++.h>
#include "hashTable.h"
using namespace std;

int main () {
    HashTable<string, string> hTable;
    ifstream file;
    file.open("../../dados.csv");
    string fst, snd;
    int op;
    string key, value;

    while(file.good()) {
        string line;
        getline(file, line, ',');
        stringstream ss(line);
        ss >> snd >> fst;
        hTable.insert(fst, snd);
    }

    while(true) {
        cout << endl << "----------------------------------------" << endl;
        cout << "TableHash implementation with DoubleHash" << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Delete all elements" << endl;
        cout << "4. Show all table values" << endl;
        cout << "5. Search table value" << endl;
        cout << "6. Number of elements" << endl;
        cout << "0. Exit" << endl;
        cout << endl << "Choose a option!!!" << endl;

        cin >> op;

        switch(op) {
            case 0:
                return 0;

            case 1:
                cout << "Insert the key" << endl;
                cin >> key;
                cout << "Insert the value" << endl;
                cin >> value;
                if (hTable.insert(key, value)) {
                    cout << "Success insertion" << endl;
                }
                break;

            case 2:
                cout << "Insert the key" << endl;
                cin >> key;
                if (hTable.remove(key)) {
                    cout << "Success deletion" << endl;
                }
                break;

            case 3:
                hTable.makeEmpty();
                cout << "Success makeEmpty" << endl;
                break;

            case 4:
                hTable.print();
                break;

            case 5:
                cout << "Insert the key" << endl;
                cin >> key;
                if(hTable.search(key, value)) {
                    cout << "Value: " << value << endl;
                }
                break;

            case 6:
                cout << "Size: " << hTable.size() << endl;
                break;

            default:
                cout << "Wrong option, the program will broken!" << endl;
                return 0;
        }

    }
	return 0;
}
