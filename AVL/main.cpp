#include <bits/stdc++.h>
#include "item.h"
#include "avl.h"
using namespace std;

struct Node {
    Tkey key;
    Tvalue value;
    int height;
    Node *left;
    Node *right;
};

int main() {
	Node *r = nullptr;

	r = avl_insert(r, 5, 1.0);
    r = avl_insert(r, 7, 2.0);
    r = avl_insert(r, 11, 3.0);
    r = avl_insert(r, 17 , 4.0);
    r = avl_insert(r, 4, 5.0);
    r = avl_insert(r, 6, 6.0);
    r = avl_insert(r, 2, 7.0);
    r = avl_insert(r, 1, 8.0);
    r = avl_insert(r, 22, 9.0);
    r = avl_insert(r, 3, 10.0);

    avl_level_traversal(r);

    r = avl_clear(r);

    return 0;
}