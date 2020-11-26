#ifndef AVL_H
#define AVL_H

#include <bits/stdc++.h>

#include "node.h"
#include "pessoa.h"

using std::cout;
using std::string;
using std::endl;
using std::max;
using std::vector;

template<typename K>
class 	AVLTree {
	private:
		Node<K> *root;

	protected:
		/* Função que realiza Rotação Direita Simples sobre um determinado Node */
		Node<K> *avl_rightRotation(Node<K> *node) {
			Node<K> *u = node->left;
			node->left = u->right;
			u->right = node;

			node->height = 1 + max(avl_height(node->left), avl_height(node->right));
			u->height = 1 + max(avl_height(u->left), avl_height(u->right));

			return u;
		}

		/* Função que realiza Rotação Esquerda Simples sobre um determinado Node */
		Node<K> *avl_leftRotation(Node<K> *node) {
			Node<K> *u = node->right;
			node->right = u->left;
			u->left = node;

			node->height = 1 + max(avl_height(node->left), avl_height(node->right));
			u->height = 1 + max(avl_height(u->left), avl_height(u->right));

			return u;
		}

		/* Função que restaura as propriedades de um Node/Arvore AVL após INSERÇÃO */
		Node<K> *avl_fixup_node(Node<K> *node, K key) {
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

		/* Função que restaura as propriedades de um Node/Arvore AVL após REMOÇÃO */
		Node<K> *avl_fixup_node_deletion(Node<K> *node) {
			node->height = 1 + max(avl_height(node->right), avl_height(node->left));
			
			int bal = avl_balance(node);
			
			if(bal > 1 && avl_balance(node->right) >= 0) {
				node = avl_leftRotation(node);
			}else if(bal > 1 && avl_balance(node->right) < 0) {
				node->right = avl_rightRotation(node->right);
				node = avl_leftRotation(node);
			}else if(bal < -1 && avl_balance(node->left) <= 0) {
				node = avl_rightRotation(node);
			}else if(bal < -1 && avl_balance(node->left) > 0) {
				node->left = avl_leftRotation(node->left);
				node = avl_rightRotation(node);
			}
			return node;
		}

		/* Função responsável por remover o PREDECESSOR de um Node */
		Node<K> *avl_delete_pred( Node<K> *root , Node<K> *node ) {
			if( node->right != nullptr ) {
				node->right = avl_delete_pred( root, node->right );
			}else {
				root->key = node->key;
				Node<K> *aux = node->left;
				delete node;
				return aux;
			}
			node = avl_fixup_node_deletion( node );
			return node;
		}

		/* Função que retorna o valor do atributo height(altura) de um Node */
		int avl_height( Node<K> *node ) {
			if( node == nullptr ) return 0;
			else return node->height;
		}

		/* Função que retorna o calculo do BALANÇO de um Node.
		   BALANÇO de um Node é definido como a diferença das alturas
		    de suas subárvores. ( Subárvore direita - Subárvore esquerda ).  */
		int avl_balance( Node<K> *node ) {
			if( node == nullptr ) return 0;
			return avl_height( node->right ) - avl_height(node->left);
		}

		/* Função que libera as subárvores de um Node e logo em seguida,
		    o libera também.											 */		
		Node<K> *avl_clear(Node<K> *node) {
			if(node != nullptr) {
				node ->left = avl_clear(node ->left);
				node ->right = avl_clear(node ->right);
				cout << "Erasing the key: " << node ->key << endl;
				delete node;
			}
			return nullptr;
		}

		/* Função que verifica se o atributo Key do Node
			possui key como PREFIXO e chama essa verificação
			para as suas subárvores.                          */
		void avl_searchPrex ( Node<K>* node, K key ) {
			if ( node == nullptr ) {
				return;
			}
			/* Se o atributo key do Node for igual ao parâmetro( key ),
				mostra os dados dos objetos Pessoa e chama a função para
				os seus filhos */
			else if ( node->compareKey(key) == 0 ) {
				avl_searchPrex ( node->left, key );
				for ( int i = 0; i < node->p.size() ; i++ ) {
					cout << node->p[i]->Cpf << " " << node->p[i]->Nome << " " << node->p[i]->SNome 
					<< " " << node->p[i]->Data << " " << node->p[i]->Cidade << endl;
				}
				avl_searchPrex ( node->right, key );
			}
			/* Se o atributo key do Node não for igual ao parâmetro( key ),
				e ele for maior lexicograficamente que o parâmetro. */
			else if ( node->compareKey(key) > 0 ) {
				avl_searchPrex ( node->left, key );
			}
			/* Se o atributo key do Node não for igual ao parâmetro( key ),
				e ele for menor lexicograficamente que o parâmetro. */
			else {
				avl_searchPrex ( node->right, key );
			}
		} 

		/* Função que verifica se o atributo key do Node
		    é igual key( passado por parâmetro).
		   Observação: se key do Node for igual a key, a lista
		    de pessoas do Node é impressa.                     */
		void avl_searchKey( Node<K> *node, K key ) {
			if( node == nullptr ) {
				return;
			}
			if( key < node->key ) {
				return avl_searchKey(node->left, key);
			}else if( key > node->key ) {
				return avl_searchKey(node->right, key);
			} 
			/* Se atributo key do Node for igual ao parâmetro( key ),
			    mostra os dados dos objetos Pessoa do Node.          */
			else {
				for ( int i = 0; i < node->p.size() ; i++ ) {
					cout << node->p[i]->Cpf << " " << node->p[i]->Nome << " " << node->p[i]->SNome 
					<< " " << node->p[i]->Data << " " << node->p[i]->Cidade << endl;
				}
				return;
			} 	
		}

		/* Função que verifica se o atributo key do Node está dentro dos 
		    limites passados por parâmetro ( range1, range2).
		   Observação: range1 = limite inferior
		   			   range2 = limite superior						     */
		void avl_searchRange( Node<K> *node, K range1, K range2 ) {
            if( node == nullptr ) {
                return;
            }
            /* Se o atributo key do Node é menor que o limite inferior */
            else if( range1 >= node->key ) {
                return avl_searchRange( node->right, range1, range2 );
            }
            /* Se o atributo key do Node é maior que o limite inferior. */
            else {
            	/* Se o atributo key do Node é menor que o limite superior.*/
                if( node->key < range2 ) {
                    for ( int i = 0; i < node->p.size() ; i++ ) {
						cout << node->p[i]->Cpf << " " << node->p[i]->Nome << " " << node->p[i]->SNome 
						<< " " << node->p[i]->Data << " " << node->p[i]->Cidade << endl;
					}
                    avl_searchRange( node->right, range1, range2 );
                }
                avl_searchRange( node->left, range1, range2 );
            }
		}

		/* Função que procura o lugar adequado dentro da árvore para inserir
		    um novo Node.                                                    */
		Node<K> *avl_insert(Node<K> *node, K key, Pessoa *p, bool &ans) {

			if(node == nullptr) {
				node = new Node<K>();
				node->key = key;
				node->p.push_back(p);
				node->left = nullptr;
				node->right = nullptr;
				node->height = 1;
				return node;
			}
			if(key < node->key) {
				node->left = avl_insert(node->left, key, p, ans);
			}else if(key > node->key) {
				node->right = avl_insert(node->right, key, p, ans);
			}else {
				node->p.push_back(p);
				return node;
			}

			/* Setando o atributo height(altura) do Node depois da inserção */
			node->height = 1 + max(avl_height(node->left), avl_height(node->right));

			/* Reestabelecer as propriedades do node/árvore */
			node = avl_fixup_node(node, key);

			ans = true;
			return node;
		}

		/* Função que procura um Node com atributo key igual a key(parâmetro), 
		    e o remove.                                                       */
		Node<K> *avl_delete( Node<K> *node, K key, bool &ans ) {

			if( node == nullptr ) {
				ans = false;
				return nullptr;
			}
			if( key < node->key ) {
				node->left = avl_delete( node->left, key, ans );
			}else if( key > node->key ) {
				node->right = avl_delete( node->right, key, ans );
			}

			/* Não possui filhos */
			else if( node->left == nullptr and node->right == nullptr ) {
				ans = true;
				delete node;
				return nullptr;
			}
			/* Possui somente um filho */
			else if( node->left == nullptr || node->right == nullptr ) {
				Node<K> *child = node->left ? node->left : node->right;
				ans = true;
				delete node;
				return child;
			}
			/* Possui os dois filhos */
			else {
				ans = true;
				node->left = avl_delete_pred( node, node->left );
			}

			/* Reestabelecer as propriedades do node/árvore */
			node = avl_fixup_node_deletion(node);

			return node;
		}

	public:

		AVLTree(void) {
			root = nullptr;
		}

		~AVLTree(void) {
			avl_clear(root);
			root = nullptr;
		}

		void searchPrex ( K key ) {
			avl_searchPrex( root, key);
		}

		bool searchKey(K key) {
			avl_searchKey(root, key);
		}

		void searchRange(K range1, K range2) {
            avl_searchRange(root, range1, range2);
		}

		bool insert(K key, Pessoa *p) {
			bool ans = false;
			root = avl_insert(root, key, p, ans);
			return ans;
		}

		bool remove(K key) {
			bool ans = false;
			root = avl_delete(root, key, ans);
			return ans;
		}
};

#endif 