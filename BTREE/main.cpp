#include <iostream>
#include "bnode.h"
#include "btree.h"
using namespace std;
const int MAX = 21;

int main() {
    Btree tree(3); // grau minimo D = 2
    
    for(int i = 1; i <= MAX; i++)
        tree.insert(i);
    
    tree.printKeys(); // Tem que programar esta funcao
    
    tree.remove(15);

    tree.printKeys();

    cout << endl;

    return 0;
}