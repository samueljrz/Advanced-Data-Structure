#include <bits/stdc++.h>
#include "item.h"
#include "bst.h"
using namespace std;

struct Node {
    Tkey key;
    Tvalue value;
    Node *left;
    Node *right;
};

Tkey bst_getKey(Node *node) {
    return node->key;
}

Tvalue bst_getValue(Node *node) {
    return node->value;
}

Node *bst_search(Node *node, Tkey mykey) {
    if(node == nullptr)
        return nullptr;
    if(node->key == mykey)
        return node;
    if(mykey < node->key)
        return bst_search(node->left, mykey);
    else 
        return bst_search(node->right, mykey);
}

Node *bst_insert(Node *node, Tkey mykey, Tvalue value) {
    if(node == nullptr) {
        node = new Node;
        node->key = mykey;
        node->value = value;
        node->left = node->right = nullptr;
    }
    else if(mykey < node->key) 
        node->left = bst_insert(node->left, mykey, value);
    else if(mykey > node->key)
        node->right = bst_insert(node->right, mykey, value);
    
    return node;
}

void bst_preorder(Node *node) {
    if(node != nullptr) {
        cout << "(" <<node->key << ", " << node->value << ")" << endl;
        bst_preorder(node->left);
        bst_preorder(node->right);
    }
}

void bst_preorder(Node *node, void f(Node*)) {
    if(node != nullptr) {
        f(node);
        bst_preorder(node->left, f);
        bst_preorder(node->right, f);
    }
}

void bst_inorder(Node *node) {
    if(node != nullptr) {
        bst_inorder(node->left);
        cout << "(" <<node->key << ", " << node->value << ")" << endl;
        bst_inorder(node->right);
    }
}

void bst_postorder(Node *node) {
    if(node != nullptr) {
        bst_postorder(node->left);
        bst_postorder(node->right);
        cout << "(" <<node->key << ", " << node->value << ")" << endl;
    }
}

int bst_height(Node *node) {
    if(node == nullptr) return 0;
    return 1 + max(bst_height(node->left), bst_height(node->right));
}

bool bst_empty(Node* node) {
    if(node == nullptr) return true;
    return false;
}

Node *bst_clear(Node *node) {
    if(node != nullptr) {
        node->left = bst_clear(node->left);
        node->right = bst_clear(node->right);
        cout << "Liberando o nó " << node->key << endl;
        delete node;
    }
    return nullptr;
}

void bst_remove_antecessor(Node *node) {
    Node *maxleft = node->left;
    Node *pai = node;

    if(maxleft->right != nullptr) {
        while(maxleft != nullptr) {
        pai = maxleft;
        maxleft = maxleft->right;
        }
    }
    node->key = maxleft->key;

    if(pai->right == maxleft) {
        pai->right = maxleft->left;
    }else {
        pai->left = maxleft->left;
    }
    delete maxleft;
}

Node *bst_remove(Node *node, Tkey key) {
    if(node == nullptr) return nullptr;
    if(key > node->key) {
        node->right = bst_remove(node->right, key);
    }else if(key < node->key) {
        node->left = bst_remove(node->left, key);
    }else if(node->left == nullptr and node->right == nullptr) {
        delete node;
        node = nullptr;
    }else if(node->left == nullptr) {
        Node *aux = node;
        node = node->right;
        delete aux;
    }else if(node->right == nullptr) {
        Node *aux = node;
        node = node->left;
        delete aux;
    }else {
        bst_remove_antecessor(node);
    }
    return node;
}

Node *bst_minimum(Node *node) {
    while(node->left != nullptr) {
        node = node->left;
    } 
    return node;
}

Node *bst_maximum(Node *node) {
    while(node->right != nullptr) {
        node = node->right;
    } 
    return node;
}

Node* bst_successor(Node* root, Node *x) {
    struct Node *aux1, *aux2;
    Tkey var = 9999999;
    aux1 = aux2 = root;
    if(root == nullptr) return nullptr;
    if(x == bst_maximum(root))return nullptr;
    if(x->right != nullptr) {
        aux1 = x->right;
        while(aux1->left != nullptr) {
            aux1 = aux1->left;
        }
        aux2 = aux1;
    }else {
        while(aux1->key != x->key) {
            if(aux1->key > x->key and aux1->key < var) {
                aux2 = aux1;
                var = aux2->key;
            }if(aux1->key < x->key) {
                aux1 = aux1->right;
            }else {
                aux1 = aux1->left;
            }
        }   
    }       
    return aux2;
}


Node* bst_predecessor(Node* root, Node *x) {
    Tkey var = -999999;
    struct Node *aux1, *aux2;
    aux1 = aux2 = root;
    if(root == nullptr) return nullptr;
    if(x == bst_minimum(root))return nullptr;
    if(x->left != nullptr) {
        aux1 = x->left;
        while(aux1->right != nullptr) {
            aux1 = aux1->right;
        }
        return aux1;
    }else {
        while(aux1 != x) {    
            if(aux1->key < x->key and aux1->key > var) {
                aux2 = aux1;
                var = aux2->key;
            }if(aux1->key > x->key) {
                aux1 = aux1->left;
            }else {
                aux1 = aux1->right;
            }
        }
    }
    return aux2;
}   