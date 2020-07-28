#ifndef AVL_H
#define AVL_H
#include "item.h"

struct Node;

Node *avl_rightRotation(Node *node);
Node *avl_leftRotation(Node *node);
Node *avl_fixup_node(Node *node, Tkey key);
Node *avl_fixup_node_deletion(Node *node);
Node *avl_delete_pred(Node *root , Node *node);

Node *avl_insert(Node *node, Tkey key, Tvalue value);
Node *avl_delete(Node *node, Tkey key);

Tkey avl_getKey(Node *node);
Tvalue avl_getValue(Node *node);
Node *avl_search(Node *node, Tkey key);
void avl_preorder(Node *node);
void avl_inorder(Node *node);
void avl_postorder(Node *node);
void avl_level_traversal(Node *node);
int avl_height(Node *node);
int avl_balance(Node *node);
int avl_sheets_number(Node *node);
int avl_size(Node *node);
Tkey avl_min_value(Node *node);
Tkey avl_max_value(Node *node);
bool avl_empty(Node *node);
Node *avl_clear(Node *node);

#endif 
