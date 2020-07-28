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

// Right Rotation in the tree, for reorganized it.
Node *avl_rightRotation(Node *node) {
	Node *u = node->left;
	node->left = u->right;
	u->right = node;

	node->height = 1 + max(avl_height(node->left), avl_height(node->right));
	u->height = 1 + max(avl_height(u->left), avl_height(u->right));

	return u;
}

// Left Rotation in the tree, for reorganized it.
Node *avl_leftRotation(Node *node) {
	Node *u = node->right;
	node->right = u->left;
	u->left = node;

	node->height = 1 + max(avl_height(node->left), avl_height(node->right));
	u->height = 1 + max(avl_height(u->left), avl_height(u->right));

	return u;
}

// Fixup the tree when your balance its wrong
Node *avl_fixup_node(Node *node, Tkey key) {
	int bal = avl_balance(node);

	if(bal < -1 and key < node->left->key) return avl_rightRotation(node);
	else if(bal < -1 and key > node->left->key) {
		node->left = avl_leftRotation(node->left);
		return avl_rightRotation(node);
	}else if(bal > 1 and key > node->right->key) return avl_leftRotation(node);
	else if(bal > 1 and key < node->right->key) {
		node->right = avl_rightRotation(node->right);
		return avl_leftRotation(node);
	}
	return node;
}

// INCOMPLETE
Node *avl_fixup_node_deletion(Node *node) {
	int bal = avl_balance(node);
	if(bal >= -1 or bal <= 1) return node;
}

// Delete pred of the specific node, help the function delete works
Node *avl_delete_pred(Node *root , Node *node) {
	if(node->right != nullptr) {
		node->right = avl_delete_pred(root, node->right);
	}else {
		root->key = node->key;
		Node *aux = node->left;
		delete node;
		return aux;
	}
	node = avl_fixup_node_deletion(node);
	return node;
}

// Insert a node in the tree
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

	node->height = 1 + max(avl_height(node->left), avl_height(node->right));

	node = avl_fixup_node(node, key);

	return node;
}

// Delete a node in the tree, INCOMPLETE!
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
	node = avl_fixup_node_deletion(node);
	return node;
}

// Get key of the node
Tkey avl_getKey(Node *node) {
    return node->key;
}

// Get value of the node
Tvalue avl_getValue(Node *node) {
    return node->value;
}

// Search a node in the tree
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

// Show in pre-order ROOT-L-R
void avl_preorder(Node *node) {
	if(node != nullptr) {
		cout << "(" << node->key << ", " << node->value << ")" << endl;
		avl_preorder(node->left);
		avl_preorder(node->right);
	}
}

// Show in in-order L-ROOT-R
void avl_inorder(Node *node) {
	if(node != nullptr) {
		avl_inorder(node->left);
		cout << "(" << node->key << ", " << node->value << ")" << endl;
		avl_inorder(node->right);
	}
}

// Show in post-order R-L-ROOT
void avl_postorder(Node *node) {
	if(node != nullptr) {
		avl_preorder(node->right);
		avl_preorder(node->left);
		cout << "(" << node->key << ", " << node->value << ")" << endl;
	}
}

// Show the tree from up to down, and left to right
void avl_level_traversal(Node *node) {
	if(node == nullptr) return;
	queue<Node*> QNode;
	QNode.push(node);
	while(!QNode.empty()) {
		Node *current = QNode.front();
		cout << "(" << current->key << ", " << current->value << ")" << endl;
		if(current->left != nullptr) QNode.push(current->left);
		if(current->right != nullptr) QNode.push(current->right);
		QNode.pop();
	}
}

// Show the height of the tree
int avl_height(Node *node) {
	if(node == nullptr) return 0;
	else return node->height;
}

// Calculate the balance of a node 
int avl_balance(Node *node) {
	if(node == nullptr) return 0;
	return avl_height(node->right) - avl_height(node->left);
}

// Count how much nodes have in the tree
int avl_size(Node *node) {
	if(node == nullptr) return 0;
	else 1 + avl_size(node->left) + avl_size(node->right);
}

// Count all the sheet of the tree
int avl_sheets_number(Node *node) {
	if(node == nullptr) return 0;
	if(node->left == nullptr and node->right == nullptr) return 1;
	return avl_sheets_number(node->left) + avl_sheets_number(node->right);
}

// Show the maximum value of the tree
Tkey avl_max_value(Node *node) {
	while(node->right != nullptr) {
        node = node->right;
    } 
    return node->key;
}

// Show the minimum value of the tree
Tkey avl_min_value(Node *node) {
	while(node->left != nullptr) {
        node = node->left;
    } 
    return node->key;
}

// Return a boolean, if tree was be empty return true another case return false
bool avl_empty(Node *node) {
	return (node == nullptr);
}

// Delete all the nodes of the tree
Node *avl_clear(Node *node) {
	if(node != nullptr) {
		node ->left = avl_clear(node ->left);
		node ->right = avl_clear(node ->right);
		cout << "Erasing the key: " << node ->key << endl;
		delete node;
	}
	return nullptr;
}