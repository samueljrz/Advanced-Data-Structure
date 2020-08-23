#ifndef NODE_H
#define NODE_H

enum Color {RED, BLACK};

//classe com template 
template<typename K, typename V>
class Node {
public:
	K key;
	V value;
	Color color;
	Node *left;
	Node *right;
	Node *parent;

};

#endif
