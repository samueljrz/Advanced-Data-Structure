#include <bits/stdc++.h>
#include "item.h"
#include "avl.h"
#include <unistd.h>
using namespace std;

struct Node {
    Tkey key;
    Tvalue value;
    int height;
    Node *left;
    Node *right;
};

int main() {
	int opc;
	Tkey key;
	Tvalue value;
	Node *r = nullptr;

    cout << "--------------------------------" << endl;
    cout << "AVL tree implementation!" << endl;
    cout << "--------------------------------" << endl;

    while(true) {
	    cout << "1. Insert element in a tree" << endl;
	    cout << "2. Clear all nodes" << endl;
	    cout << "3. Pre-order route" << endl;
	    cout << "4. In-order route" << endl;
	    cout << "5. Post-order route" << endl;
	    cout << "6. Search a node" << endl;
	    cout << "7. Tree height" << endl;
	    cout << "8. Delete a node by key" << endl;
	    cout << "9. Exit" << endl;
	    cout << "Get in with your choose: " << endl;

	    cin >> opc;

	    switch(opc) {
	    	case 1: 
	    		system("clear");
	    		cout << "Insert the key" << endl;
	    		cin >> key;
	    		while(avl_search(r, key) != nullptr) {
	    			cout << "Key already exists, please, insert another key: " << endl;
	    			cin >> key;
	    		}
	    		cout << "Insert the value" << endl;
	    		cin >> value;
	    		r = avl_insert(r, key, value);
	    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 2: 
	    		system("clear");
	    		cout << "Clear all nodes: " << endl;
	    		avl_clear(r);
	    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 3: 
	    		system("clear");
	    		cout << "Pre-order: " << endl;
	    		avl_preorder(r);
	    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 4: 
	    		system("clear");
	    		cout << "In-order: " << endl;
	    		avl_inorder(r);
	    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 5: 
	    		system("clear");
	    		cout << "Post-order: " << endl;
	    		avl_postorder(r);
	    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 6: 
	    		system("clear");
	    		cout << "Insert the key" << endl;
	    		cin >> key;
	    		if(avl_search(r, key) == nullptr) {
	    			cout << "The key doesn't match any values" << endl;
	    		}else {
	    			cout << key << ": " << avl_search(r, key)->value << endl;
	    		}
	    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 7: 
	    		system("clear");
	    		cout << "Tree height: " << avl_height(r) << endl;
	    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 8: 
	    		system("clear");
	    		cout << "Insert the key: " << endl;
	    		cin >> key;
	    		while(avl_search(r, key) == nullptr) {
	    			cout << "Key doesn't exists, please, insert another key: " << endl;
	    			cin >> key;
	    		}
	    		r = avl_delete(r, key);
	    		cout << "Deleted: " << key << endl;
	    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 9: 
	    		system("clear");
	    		return 0;

	    	default: 
	    		system("clear");
	    		cout << "Wrong option, Program going to end" << endl;
	    		return 0;
	    }
    }
}