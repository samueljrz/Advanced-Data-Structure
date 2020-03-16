#include <iostream>
#include <queue>
#include "avl.h"
#include "item.h"
using std::cout;
using std::endl;
using std::max;

struct Node {
    Tkey key;
    Tvalue value;
    int height;
    Node *left;
    Node *right;
};

node *rightRotation(Node *node) {
	Node *u = node->left;
	node->left = u->right;
	u->right = node;

	node->height = 1 + max(height(node->left), height(node->right));
	u->height = 1 + max(height(u->left), height(u->right));

	return u;
}

node *leftRotation(Node *node) {
	Node *u = node->right;
	node->right = u->left;
	u->left = node;

	node->height = 1 + max(height(node->left), height(node->right));
	u->height = 1 + max(height(u->left), height(u->right));

	return u;
}

Node *fixup_node(Node *node, Tkey key) {
	int bal = avl_balance(node);

	if(bal < -1 and key < node->left->key) return rightRotation(node);
	else if(bal < -1 and key > node->left->key) {
		node->left = leftRotation(node->left);
		return rightRotation(node);
	}else if(bal > 1 and key > node->right->key) return leftRotation(node);
	else if(bal > 1 and key < node->right->key) {
		node->right = rightRotation(node->right);
		return leftRotation(node);
	}
	return node;
}

Node *fixup_node_deletion(Node *node) {
	int bal = avl_balance(node);
	if(bal >= -1 or bal <= 1) return node;
}

Node *delete_pred(Node *root , Node *node) {
	if(node->right != nullptr) {
		node->right = delete_predecessor(root, node->right);
	}else {
		root->key = node->key;
		Node *aux = node->left;
		delete node;
		return aux;
	}
	node = fixup_node_deletion(node);
	return node;
}

Node *avl_insert(Node *node, Tkey key, Tvalue value) {
	if(node == nullptr) {
		Node *node = new Node();
		node->key = key;
		node->value = value;
		node->left = nullptr;
		node->right = nullptr;
		node->height = 1;
		return node;
	}
	if(key < node->key) {
		node->left = avl_insert(node->left, key, value);
	}else if(key > node->key) {
		node->right = avl_insert(node->right, key, value);
	}else {
		return node;
	}

	node->height = 1 + max(height(node->left), height(node-->right));

	node = fixup_node(node, key);

	return node;
}

Node *avl_delete(Node *node, Tkey key) {
	if(node == nullptr) return nullptr;
	if(key < node->key) {
		node->left = avl_delete(node->left, key);
	}else if(key > node->key) {
		node->right = avl_delete(node->right, key);
	}else if(node->left == nullptr and node->right == nullptr) {
		delete node;
		return nullptr;
	}else if(node->left == nullptr || node->right == nullptr) {
		Node *child = node->left ? node->left : node->right;
		delete node;
		return child;
	}else {
		node->left = avl_delete_pred(node, node->left);
	}
	node = fixup_node_deletion(node);
	return node;
}

Tkey avl_getKey(Node *node) {
    return node->key;
}

Tvalue avl_getValue(Node *node) {
    return node->value;
}

Node *avl_search(Node *node, Tkey key) {
	if(node == nullptr) {
		return nullptr;
	}
	if(key < node->key) {
		return avl_search(node->left, key);
	}else if(key > node->key) {
		return avl_search(node->right, key);
	}else 	
		return node;
}

void avl_preorder(Node *node) {
	if(node != nullptr) {
		cout << "(" << node->key << ", " << node->value << ")" << endl;
		avl_preorder(node->left);
		avl_preorder(node->right);
	}
}

void avl_inorder(Node *node) {
	if(node != nullptr) {
		avl_inorder(node->left);
		cout << "(" << node->key << ", " << node->value << ")" << endl;
		avl_inorder(node->right);
	}
}

void avl_level_traversal(Node *node) {
	if(node == nullptr) return nullptr;
	queue<Node*> QNode;
	Q.push(node);
	while(!Q.empty()) {
		Node *current = Q.front();
		cout << "(" << current->key << ", " << current->value << ")" << endl;
		if(current->left != nullptr) Q.push(current->left);
		if(current->right != nullptr) Q.push(current->right);
		Q.pop();
	}
}

int avl_height(Node *node) {
	if(node == nullptr) return 0;
	else return node->height;
}

int avl_balance(Node *node) {
	if(node == nullptr) return 0;
	return avl_height(node->right) - avl_height(node->left);
}

int avl_size(Node *node) {
	if(node == nullptr) return 0;
	else 1 + avl_size(node->left) + avl_size(node->right);
}

bool avl_empty(Node *node) {
	return (node == nullptr);
}

Node *avl_clear(Node *node) {
	if(node != nullptr) {
		node ->left = avl_clear(node ->left);
		node ->right = avl_clear(node ->right);
		cout << "Removendo chave " << node ->key << endl;
		delete node;
	}
	return nullptr;
}