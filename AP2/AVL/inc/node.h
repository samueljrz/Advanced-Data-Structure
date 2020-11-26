#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>

#include "pessoa.h"

using std::string;
using std::vector;
 
template<typename K>
class Node {
public:
	K key;
	vector<Pessoa*> p;
	int height;
	Node *left;
	Node *right;

	/* Função que compara o atributo Key do Node
		a uma outra chave, passada por parêmetro.
	   Retornos: 0 se forem iguais;
	            -1 se atributo key for menor(lexicograficamente)
	             1 se atributo key for maior(lexicograficamente)
	*/
	int compareKey( K k ) {

		/* Atributo Key do Node é menor que k */
		if ( this->key.size() < k.size() ) {
			for ( int i=0 ; i < (int)this->key.size() ; i++ ) {
			    if( this->key[i] < k[i] ) {
			        return (-1);
			    }else if( this->key[i] > k[i] ) {
			        return 1;
		 	    }    
			}
			return -1;
		}

        /* Atributo Key do Node é maior ou igual que k */
        if ( this->key.size() >= k.size() ) {
			for ( int i=0 ; i < (int)k.size() ; i++ ) {
			    if( this->key[i] < k[i] ) {
			        return (-1);
			    }else if( this->key[i] > k[i] ) {
			        return 1;
			    }    
			}
			return 0;
		}
	}

	//friend AVLTree;

};

#endif
