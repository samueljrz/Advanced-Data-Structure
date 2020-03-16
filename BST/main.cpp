#include <bits/stdc++.h>
#include "item.h"
#include "bst.h"

using namespace std;

struct Node {
    Tkey key;
    Tvalue value;
    Node* left;
    Node* right;
};

void func(Node* node){
    cout << (2 * bst_getKey(node)) << endl;
}

int main(){
    Node* r = nullptr;

    /*root = bst_insert(root, 20, 45.9);
    root->left = bst_insert(root, 10, 5.5);
    root->right = bst_insert(root, 25, 6.6);
    Sr = root->right->right = bst_insert(root, 30, 7.7);
    Sr->left = bst_insert(root, 26, 6.7);*/

    r = bst_insert(r, 8, 1.0);
    r = bst_insert(r, 3, 2.0);
    r = bst_insert(r, 13, 3.0);
    r = bst_insert(r, 7 , 4.0);
    r = bst_insert(r, 14, 5.0);
    r = bst_insert(r, 1, 6.0);
    r = bst_insert(r, 10, 7.0);
    r = bst_insert(r, 12, 8.0);
    r = bst_insert(r, 4, 9.0);
    r = bst_insert(r, 5, 10.0);

    //bst_inorder(r);
    bst_preorder(r);
   // cout << bst_search(r, 5) << endl;

    cout << (bst_remove(r, 3))->key << endl;

    //bst_inorder(r);
    

    //cout << bst_predecessor(r, bst_search(r, 5))->key << endl;
    //cout << bst_successor(r, bst_search(r, 5))->key << endl;
     
    //cout << bst_height(root) << endl;
    r = bst_clear(r);

    return 0;
}