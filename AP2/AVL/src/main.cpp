#include <bits/stdc++.h>
#include <unistd.h>

#include "avl.h"
#include "pessoa.h"
#include "controllers.h"

using namespace std;

int main() {
	int opc;
	string cpf, str, data1, data2;
	AVLTree<string> CPF;
	AVLTree<int> DATA;
	AVLTree<string> NOME;
	vector<Pessoa> pessoas;
	ifstream file;
	file.open("../data.csv");

	while(file.good()) {
		string line;
		vector<string> aux;
		getline(file, line);
		aux = split(line, ",");
		if(aux.size() == 5) {
			pessoas.push_back(Pessoa(aux[0], aux[1], aux[2], aux[3], aux[4]));
		}
	}

	for(int i=0; i<pessoas.size(); i++) {
		CPF.insert(pessoas[i].Cpf, &pessoas[i]);
		DATA.insert(dataToInt(pessoas[i].Data), &pessoas[i]);
		NOME.insert(pessoas[i].Nome, &pessoas[i]);
	}
	
    while(true) {
    	cout << "--------------------------------" << endl;
    	cout << "AVL AP2 implementation!" << endl;
    	cout << "--------------------------------" << endl;
	    cout << "1. Search a CPF" << endl;
	    cout << "2. Search a NOME" << endl;
	    cout << "3. Search a DATA" << endl;
	    cout << "4. Exit" << endl;
	    cout << "Get in with your choose: " << endl;

	    cin >> opc;

	    switch(opc) {
	    	case 1: 
	    		system("clear");
	    		cout << "Insert the CPF" << endl;
	    		cin >> cpf;
	    		CPF.searchKey(cpf);
	    		cout << "Wait 6 seconds for come back to the menu!!!" << endl;
	    		usleep(6000000);
	    		system("clear");
	    		break;

	    	case 2: 
	    		system("clear");
	    		cout << "Insert the string" << endl;
	    		cin >> str;
	    		NOME.searchPrex(str);
	    		cout << "Wait 6 seconds for come back to the menu!!!" << endl;
	    		usleep(6000000);
	    		system("clear");
	    		break;

	    	case 3:
	    		system("clear");
	    		cout << "Insert the First Data" << endl;
	    		cin >> data1;
	    		cout << "Insert the Second Data" << endl;
	    		cin >> data2;
	    		DATA.searchRange(dataToInt(data1), dataToInt(data2));
	    		cout << "Wait 6 seconds for come back to the menu!!!" << endl;
	    		usleep(6000000);
	    		system("clear");
	    		break;

	    	case 4: 
	    		system("clear");
	    		return 0;

	    	default: 
	    		system("clear");
	    		cout << "Wrong option, Program going to end" << endl;
	    		return 0;
	    }
    }
    
    return 0;
}