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
	int opc, k;
	string in, qq;
	Node *r = nullptr;

    cout << "--------------------------------" << endl;
    cout << "AVL tree implementation!" << endl;
    cout << "--------------------------------" << endl;

    while(true) {
	    cout << "1. Insert element in a tree" << endl;
	    cout << "2. Pre-order route" << endl;
	    cout << "3. In-order route" << endl;
	    cout << "4. Post-order route" << endl;
	    cout << "5. Tree height" << endl;
	    cout << "6. Number of sheets" << endl;
	    cout << "7. Max and Min value of the tree" << endl;
	    cout << "8. Exit" << endl;
	    cout << "Get in with your choose: " << endl;

	    cin >> opc;

	    switch(opc) {
	    	case 1: 
	    		system("clear");
	    		cout << "Insert the key" << endl;
	    		cin >> k;
	    		while(avl_search(r, k) != nullptr) {
	    			cout << "Key already exists, please, insert another key" << endl;
	    			cin >> k;
	    		}
	    		cout << "Insert the value" << endl;
	    		cin >> in;
	    		r = avl_insert(r, k, in);
	    		cout << "Wait 3 seconds for come back to menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 2: 
	    		system("clear");
	    		cout << "Pre-order: " << endl;
	    		avl_preorder(r);
	    		cout << "Wait 3 seconds for come back to menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 3: 
	    		system("clear");
	    		cout << "In-order: " << endl;
	    		avl_inorder(r);
	    		cout << "Wait 3 seconds for come back to menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 4: 
	    		system("clear");
	    		cout << "Post-order: " << endl;
	    		avl_postorder(r);
	    		cout << "Wait 3 seconds for come back to menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 5: 
	    		system("clear");
	    		cout << "Tree height: " << avl_height(r) << endl;
	    		cout << "Wait 3 seconds for come back to menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 6: 
	    		system("clear");
	    		cout << "Number of sheets: " << endl;
	    		cout << avl_sheets_number(r) << endl;
	    		cout << "Wait 3 seconds for come back to menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 7: 
	    		system("clear");
	    		cout << "Max and Min value of the tree: " << endl;
	    		cout << "Max: " << avl_max_value(r) << " Min: " << avl_min_value(r) << endl;
	    		cout << "Wait 3 seconds for come back to menu!!!" << endl;
	    		usleep(3000000);
	    		system("clear");
	    		break;

	    	case 8: 
	    		system("clear");
	    		return 0;

	    	default: 
	    		system("clear");
	    		cout << "Wrong option, Program going to end" << endl;
	    		return 0;
	    }
    }
}