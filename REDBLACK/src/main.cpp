#include <bits/stdc++.h>
#include "Node.h"
#include "RBTree.h"
#include <unistd.h>
using namespace std;	

int main() {
	int opc;

	cout << "--------------------------------" << endl;
	cout << "REDBLACK tree implementation!" << endl;
	cout << "--------------------------------" << endl;
	cout << "SELECIONE O TIPO TANTO DA KEY, QUANTO DO VALUE DA ARVORE!!!" << endl;
	cout << "1: INT - INT " << endl;
	cout << "2: INT - DOUBLE " << endl;
	cout << "3: INT - STRING " << endl;
	cout << "4: DOUBLE - DOUBLE " << endl;
	cout << "5: DOUBLE - INT " << endl;
	cout << "6: DOUBLE - STRING " << endl;
	cout << "7: STRING - STRING " << endl;
	cout << "8: STRING - INT " << endl;
	cout << "9: STRING - DOUBLE " << endl;

	cin >> opc;

	switch(opc) {
		case 1:
		{
			int key, value;
			RBTree<int, int> Tree(0);
			int opc;
			int v;

			while(true) {
				system("clear");
				cout << "--------------------------------" << endl;
		    	cout << "REDBLACK tree implementation!" << endl;
		    	cout << "--------------------------------" << endl;
			    cout << "1. Insert element in a tree" << endl;
			    cout << "2. Remove element in a tree" << endl;
			    cout << "3. Clear the tree" << endl;
			    cout << "4. Pre-order route" << endl;
			    cout << "5. Search a node" << endl;
			    cout << "6. Tree black height" << endl;
			    cout << "7. Exit" << endl;
			    cout << "Get in with your choose: " << endl;

			    cin >> opc;

			    switch(opc) {
			    	case 1: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		while(Tree.search(key, v)) {
			    			cout << "Key: " << key << " already exists, please, insert another key: " << endl;
			    			cin >> key;
			    		}
			    		cout << "Insert the value" << endl;
			    		cin >> value;
			    		Tree.insert(key, value);
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 2: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			Tree.remove(key);
			    		}else {
			    			cout << "Key: " << key << "doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		
			    		break;


			    	case 3: 
			    		system("clear");
			    		cout << "Clear all nodes!!!" << endl;
			    		Tree.clearAll();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 4: 
			    		system("clear");
			    		cout << "Pre-order: " << endl;
			    		Tree.preorder();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 5: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			cout << "Value: " << v << endl;
			    		}else {
			    			cout << "Key doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 6: 
			    		system("clear");
			    		cout << "Tree Black Height: " << Tree.blackheight() << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 7: 
			    		system("clear");
	    				return 0;

			    	default: 
			    		system("clear");
			    		cout << "Wrong option, Program going to end" << endl;
			    		return 0;
			    }
		    }
		  	break;
		}

		case 2:
		{
			int key;
			double value;
			RBTree<int, double> Tree(0);
			int opc;
			double v;

			while(true) {
				system("clear");
				cout << "--------------------------------" << endl;
		    	cout << "REDBLACK tree implementation!" << endl;
		    	cout << "--------------------------------" << endl;
			    cout << "1. Insert element in a tree" << endl;
			    cout << "2. Remove element in a tree" << endl;
			    cout << "3. Clear the tree" << endl;
			    cout << "4. Pre-order route" << endl;
			    cout << "5. Search a node" << endl;
			    cout << "6. Tree black height" << endl;
			    cout << "7. Exit" << endl;
			    cout << "Get in with your choose: " << endl;

			    cin >> opc;

			    switch(opc) {
			    	case 1: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		while(Tree.search(key, v)) {
			    			cout << "Key: " << key << " already exists, please, insert another key: " << endl;
			    			cin >> key;
			    		}
			    		cout << "Insert the value" << endl;
			    		cin >> value;
			    		Tree.insert(key, value);
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 2: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			Tree.remove(key);
			    		}else {
			    			cout << "Key: " << key << "doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		
			    		break;


			    	case 3: 
			    		system("clear");
			    		cout << "Clear all nodes!!!" << endl;
			    		Tree.clearAll();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 4: 
			    		system("clear");
			    		cout << "Pre-order: " << endl;
			    		Tree.preorder();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 5: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			cout << "Value: " << v << endl;
			    		}else {
			    			cout << "Key doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 6: 
			    		system("clear");
			    		cout << "Tree Black Height: " << Tree.blackheight() << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 7: 
			    		system("clear");
	    				return 0;

			    	default: 
			    		system("clear");
			    		cout << "Wrong option, Program going to end" << endl;
			    		return 0;
			    }
		    }
		  	break;
		}

		case 3:
		{
			int key;
			string value;
			RBTree<int, string> Tree(0);
			int opc;
			string v;

			while(true) {
				system("clear");
				cout << "--------------------------------" << endl;
		    	cout << "REDBLACK tree implementation!" << endl;
		    	cout << "--------------------------------" << endl;
			    cout << "1. Insert element in a tree" << endl;
			    cout << "2. Remove element in a tree" << endl;
			    cout << "3. Clear the tree" << endl;
			    cout << "4. Pre-order route" << endl;
			    cout << "5. Search a node" << endl;
			    cout << "6. Tree black height" << endl;
			    cout << "7. Exit" << endl;
			    cout << "Get in with your choose: " << endl;

			    cin >> opc;

			    switch(opc) {
			    	case 1: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		while(Tree.search(key, v)) {
			    			cout << "Key: " << key << " already exists, please, insert another key: " << endl;
			    			cin >> key;
			    		}
			    		cout << "Insert the value" << endl;
			    		cin >> value;
			    		Tree.insert(key, value);
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 2: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			Tree.remove(key);
			    		}else {
			    			cout << "Key: " << key << "doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		
			    		break;


			    	case 3: 
			    		system("clear");
			    		cout << "Clear all nodes!!!" << endl;
			    		Tree.clearAll();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 4: 
			    		system("clear");
			    		cout << "Pre-order: " << endl;
			    		Tree.preorder();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 5: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			cout << "Value: " << v << endl;
			    		}else {
			    			cout << "Key doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 6: 
			    		system("clear");
			    		cout << "Tree Black Height: " << Tree.blackheight() << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 7: 
			    		system("clear");
	    				return 0;

			    	default: 
			    		system("clear");
			    		cout << "Wrong option, Program going to end" << endl;
			    		return 0;
			    }
		    }
		  	break;
		}

		case 4: 
		{
			double key, value;
			RBTree<double, double> Tree(0.0);
			int opc;
			double v;

			while(true) {
				system("clear");
				cout << "--------------------------------" << endl;
		    	cout << "REDBLACK tree implementation!" << endl;
		    	cout << "--------------------------------" << endl;
			    cout << "1. Insert element in a tree" << endl;
			    cout << "2. Remove element in a tree" << endl;
			    cout << "3. Clear the tree" << endl;
			    cout << "4. Pre-order route" << endl;
			    cout << "5. Search a node" << endl;
			    cout << "6. Tree black height" << endl;
			    cout << "7. Exit" << endl;
			    cout << "Get in with your choose: " << endl;

			    cin >> opc;

			    switch(opc) {
			    	case 1: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		while(Tree.search(key, v)) {
			    			cout << "Key: " << key << " already exists, please, insert another key: " << endl;
			    			cin >> key;
			    		}
			    		cout << "Insert the value" << endl;
			    		cin >> value;
			    		Tree.insert(key, value);
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 2: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			Tree.remove(key);
			    		}else {
			    			cout << "Key: " << key << "doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		
			    		break;


			    	case 3: 
			    		system("clear");
			    		cout << "Clear all nodes!!!" << endl;
			    		Tree.clearAll();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 4: 
			    		system("clear");
			    		cout << "Pre-order: " << endl;
			    		Tree.preorder();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 5: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			cout << "Value: " << v << endl;
			    		}else {
			    			cout << "Key doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 6: 
			    		system("clear");
			    		cout << "Tree Black Height: " << Tree.blackheight() << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 7: 
			    		system("clear");
	    				return 0;

			    	default: 
			    		system("clear");
			    		cout << "Wrong option, Program going to end" << endl;
			    		return 0;
			    }
		    }
		  	break;
		}

		case 5: 
		{
			double key;
			int value;
			RBTree<double, int> Tree(0.0);
			int opc;
			int v;

			while(true) {
				system("clear");
				cout << "--------------------------------" << endl;
		    	cout << "REDBLACK tree implementation!" << endl;
		    	cout << "--------------------------------" << endl;
			    cout << "1. Insert element in a tree" << endl;
			    cout << "2. Remove element in a tree" << endl;
			    cout << "3. Clear the tree" << endl;
			    cout << "4. Pre-order route" << endl;
			    cout << "5. Search a node" << endl;
			    cout << "6. Tree black height" << endl;
			    cout << "7. Exit" << endl;
			    cout << "Get in with your choose: " << endl;

			    cin >> opc;

			    switch(opc) {
			    	case 1: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		while(Tree.search(key, v)) {
			    			cout << "Key: " << key << " already exists, please, insert another key: " << endl;
			    			cin >> key;
			    		}
			    		cout << "Insert the value" << endl;
			    		cin >> value;
			    		Tree.insert(key, value);
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 2: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			Tree.remove(key);
			    		}else {
			    			cout << "Key: " << key << "doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		
			    		break;


			    	case 3: 
			    		system("clear");
			    		cout << "Clear all nodes!!!" << endl;
			    		Tree.clearAll();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 4: 
			    		system("clear");
			    		cout << "Pre-order: " << endl;
			    		Tree.preorder();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 5: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			cout << "Value: " << v << endl;
			    		}else {
			    			cout << "Key doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 6: 
			    		system("clear");
			    		cout << "Tree Black Height: " << Tree.blackheight() << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 7: 
			    		system("clear");
	    				return 0;

			    	default: 
			    		system("clear");
			    		cout << "Wrong option, Program going to end" << endl;
			    		return 0;
			    }
		    }
		  	break;
		}

		case 6: 
		{
			double key;
			string value;
			RBTree<double, string> Tree(0.0);
			int opc;
			string v;

			while(true) {
				system("clear");
				cout << "--------------------------------" << endl;
		    	cout << "REDBLACK tree implementation!" << endl;
		    	cout << "--------------------------------" << endl;
			    cout << "1. Insert element in a tree" << endl;
			    cout << "2. Remove element in a tree" << endl;
			    cout << "3. Clear the tree" << endl;
			    cout << "4. Pre-order route" << endl;
			    cout << "5. Search a node" << endl;
			    cout << "6. Tree black height" << endl;
			    cout << "7. Exit" << endl;
			    cout << "Get in with your choose: " << endl;

			    cin >> opc;

			    switch(opc) {
			    	case 1: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		while(Tree.search(key, v)) {
			    			cout << "Key: " << key << " already exists, please, insert another key: " << endl;
			    			cin >> key;
			    		}
			    		cout << "Insert the value" << endl;
			    		cin >> value;
			    		Tree.insert(key, value);
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 2: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			Tree.remove(key);
			    		}else {
			    			cout << "Key: " << key << "doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		
			    		break;


			    	case 3: 
			    		system("clear");
			    		cout << "Clear all nodes!!!" << endl;
			    		Tree.clearAll();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 4: 
			    		system("clear");
			    		cout << "Pre-order: " << endl;
			    		Tree.preorder();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 5: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			cout << "Value: " << v << endl;
			    		}else {
			    			cout << "Key doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 6: 
			    		system("clear");
			    		cout << "Tree Black Height: " << Tree.blackheight() << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 7: 
			    		system("clear");
	    				return 0;

			    	default: 
			    		system("clear");
			    		cout << "Wrong option, Program going to end" << endl;
			    		return 0;
			    }
		    }
		  	break;
		}

		case 7: 
		{
			string key, value;
			RBTree<string, string> Tree("0");
			int opc;
			string v;

			while(true) {
				system("clear");
				cout << "--------------------------------" << endl;
		    	cout << "REDBLACK tree implementation!" << endl;
		    	cout << "--------------------------------" << endl;
			    cout << "1. Insert element in a tree" << endl;
			    cout << "2. Remove element in a tree" << endl;
			    cout << "3. Clear the tree" << endl;
			    cout << "4. Pre-order route" << endl;
			    cout << "5. Search a node" << endl;
			    cout << "6. Tree black height" << endl;
			    cout << "7. Exit" << endl;
			    cout << "Get in with your choose: " << endl;

			    cin >> opc;

			    switch(opc) {
			    	case 1: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		while(Tree.search(key, v)) {
			    			cout << "Key: " << key << " already exists, please, insert another key: " << endl;
			    			cin >> key;
			    		}
			    		cout << "Insert the value" << endl;
			    		cin >> value;
			    		Tree.insert(key, value);
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 2: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			Tree.remove(key);
			    		}else {
			    			cout << "Key: " << key << "doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		
			    		break;


			    	case 3: 
			    		system("clear");
			    		cout << "Clear all nodes!!!" << endl;
			    		Tree.clearAll();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 4: 
			    		system("clear");
			    		cout << "Pre-order: " << endl;
			    		Tree.preorder();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 5: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			cout << "Value: " << v << endl;
			    		}else {
			    			cout << "Key doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 6: 
			    		system("clear");
			    		cout << "Tree Black Height: " << Tree.blackheight() << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 7: 
			    		system("clear");
	    				return 0;

			    	default: 
			    		system("clear");
			    		cout << "Wrong option, Program going to end" << endl;
			    		return 0;
			    }
		    }
		  	break;
		}

		case 8:
		{
			string key;
			int value;
			RBTree<string, int> Tree("0");
			int opc;
			int v;

			while(true) {
				system("clear");
				cout << "--------------------------------" << endl;
		    	cout << "REDBLACK tree implementation!" << endl;
		    	cout << "--------------------------------" << endl;
			    cout << "1. Insert element in a tree" << endl;
			    cout << "2. Remove element in a tree" << endl;
			    cout << "3. Clear the tree" << endl;
			    cout << "4. Pre-order route" << endl;
			    cout << "5. Search a node" << endl;
			    cout << "6. Tree black height" << endl;
			    cout << "7. Exit" << endl;
			    cout << "Get in with your choose: " << endl;

			    cin >> opc;

			    switch(opc) {
			    	case 1: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		while(Tree.search(key, v)) {
			    			cout << "Key: " << key << " already exists, please, insert another key: " << endl;
			    			cin >> key;
			    		}
			    		cout << "Insert the value" << endl;
			    		cin >> value;
			    		Tree.insert(key, value);
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 2: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			Tree.remove(key);
			    		}else {
			    			cout << "Key: " << key << "doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		
			    		break;


			    	case 3: 
			    		system("clear");
			    		cout << "Clear all nodes!!!" << endl;
			    		Tree.clearAll();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 4: 
			    		system("clear");
			    		cout << "Pre-order: " << endl;
			    		Tree.preorder();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 5: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			cout << "Value: " << v << endl;
			    		}else {
			    			cout << "Key doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 6: 
			    		system("clear");
			    		cout << "Tree Black Height: " << Tree.blackheight() << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 7: 
			    		system("clear");
	    				return 0;

			    	default: 
			    		system("clear");
			    		cout << "Wrong option, Program going to end" << endl;
			    		return 0;
			    }
		    }
		  	break;
		}

		case 9:
		{
			string key;
			double value;
			RBTree<string, double> Tree("0");
			int opc;
			double v;

			while(true) {
				system("clear");
				cout << "--------------------------------" << endl;
		    	cout << "REDBLACK tree implementation!" << endl;
		    	cout << "--------------------------------" << endl;
			    cout << "1. Insert element in a tree" << endl;
			    cout << "2. Remove element in a tree" << endl;
			    cout << "3. Clear the tree" << endl;
			    cout << "4. Pre-order route" << endl;
			    cout << "5. Search a node" << endl;
			    cout << "6. Tree black height" << endl;
			    cout << "7. Exit" << endl;
			    cout << "Get in with your choose: " << endl;

			    cin >> opc;

			    switch(opc) {
			    	case 1: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		while(Tree.search(key, v)) {
			    			cout << "Key: " << key << " already exists, please, insert another key: " << endl;
			    			cin >> key;
			    		}
			    		cout << "Insert the value" << endl;
			    		cin >> value;
			    		Tree.insert(key, value);
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 2: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			Tree.remove(key);
			    		}else {
			    			cout << "Key: " << key << "doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		
			    		break;


			    	case 3: 
			    		system("clear");
			    		cout << "Clear all nodes!!!" << endl;
			    		Tree.clearAll();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 4: 
			    		system("clear");
			    		cout << "Pre-order: " << endl;
			    		Tree.preorder();
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 5: 
			    		system("clear");
			    		cout << "Insert the key" << endl;
			    		cin >> key;
			    		if(Tree.search(key, v)) {
			    			cout << "Value: " << v << endl;
			    		}else {
			    			cout << "Key doesn't exists" << endl;
			    		}
			    		cout << "Wait 3 seconds for come back to the menu!!!" << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 6: 
			    		system("clear");
			    		cout << "Tree Black Height: " << Tree.blackheight() << endl;
			    		usleep(3000000);
			    		system("clear");
			    		break;

			    	case 7: 
			    		system("clear");
	    				return 0;

			    	default: 
			    		system("clear");
			    		cout << "Wrong option, Program going to end" << endl;
			    		return 0;
			    }
		    }
		  	break;
		}
	}
	return 0;
}