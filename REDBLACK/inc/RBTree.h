#ifndef RBTREE_H
#define RBTREE_H
#include "Node.h"
#include <stack>
#include <string>

using std::cout;
using std::stack;
using std::string;
using std::endl;

//Classe RBTree com template
template<typename K, typename V>
class RBTree {
	private:
		Node<K, V> *root;
		Node<K, V> *nil;

	protected:
		// left rotation para ajudar os concertos na hora de inserção e remoção
		void left_rotate(Node<K, V> *x) {
			Node<K, V> *y = x->right;
			x->right = y->left;
			if(y->left != nil) {
				y->left->parent = x;
			}
			y->parent = x->parent;
			if(x->parent == nil) {
				root = y;
			}else if(x == x->parent->left) {
				x->parent->left = y;
			}else {
				x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		}

		// right rotation para ajudar os concertos na hora de inserção e remoção
		void right_rotate(Node<K, V> *x) {
			Node<K, V> *y = x->left;
			x->left = y->right;
			if(y->right != nil) {
				y->right->parent = x;
			}
			y->parent = x->parent;
			if(x->parent == nil) {
				root = y;
			}else if(x == x->parent->right) {
				x->parent->right = y;
			}else {
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}

		// função que insere a chave no seu respectivo local 
		void RBinsert(Node<K, V> *z) {
			Node<K, V> *father = nil;
			Node<K, V> *son = root;
			while(son != nil) {
				father = son;
				if (z->key == son->key) { 
					delete z;
					return; 
				}
				son = (z->key < son->key) ? son->left : son->right;
			}
			z->parent = father;
			if(father == nil) {
				root = z;
			}else if (z->key < father->key) {
				father->left = z;
			}else {
				father->right = z;
			} 
			z->left = z->right = nil;
			z->color = RED;
			RBinsert_fixUp(z);
		}

		// função que concerta algum erro que quebre as 5 caracteristicas da RBTree apos a inserção
		void RBinsert_fixUp(Node<K, V> *z) {
			while(z->parent->color == RED) {
				if(z->parent == z->parent->parent->left) {
					Node<K, V> *uncle = z->parent->parent->right;
					if(uncle->color == RED) {
						z->parent->color = BLACK;
						uncle->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent;
					}else {
						if (z == z->parent->right) {
							z = z->parent;
							left_rotate(z);
						}
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						right_rotate(z->parent->parent);
					}
				}else { 
					Node<K, V> *uncle = z->parent->parent->left;
					if(uncle->color == RED) {
						z->parent->color = BLACK;
						uncle->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent;
					}else {
						if(z == z->parent->left) {
							z = z->parent;
							right_rotate(z);
						}
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						left_rotate(z->parent->parent);
					}
				}	
			}
			root->color = BLACK; 
		}

		// função que deleta o nó da arvore
		void RBdelete(Node<K, V> *z) {
			Node<K, V> *y; 
			Node<K, V> *x; 
			if(z->left == nil || z->right == nil) {
				y = z;
			}else {
				y = minimum(z->right); 
			}
			if(y->left != nil) {
				x = y->left;
			}else {
				x = y->right;
			}
			
			x->parent = y->parent;
			
			if(y->parent == nil) {
				root = x;
			}else {
				if(y == y->parent->left) {
					y->parent->left = x;
				}else {
					y->parent->right = x;
				}	
			}
			if(y != z) {
				z->key = y->key;
				z->value = y->value;

			}
			if(y->color == BLACK) {
				RBdelete_fixUp(x);
			}
			delete y;
		}

		// função que consertar os possiveis erros que pode acontecer apos deletar um no, se ferir alguma das 5 caracteristicas
		void RBdelete_fixUp(Node<K, V> *x) {
			while(x != root && x->color == BLACK) {
				if(x == x->parent->left) {
					Node<K, V> *w = x->parent->right;
					if(w->color == RED) {
						w->color = BLACK;
						x->parent->color = RED;
						left_rotate(x->parent);
						w = x->parent->right;
					}
					if(w->left->color == BLACK && w->right->color == BLACK) {
						w->color = RED;
						x = x->parent;
					}else {
						if(w->right->color == BLACK) {
							w->left->color = BLACK;
							w->color = RED;
							right_rotate(w);
							w = x->parent->right;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						left_rotate(x->parent);
						x = root;
					}
				}else {
					Node<K, V> *w = x->parent->left;
					if(w->color == RED) {
						w->color = BLACK;
						x->parent->color = RED;
						right_rotate(x->parent);
						w = x->parent->left;
					}
					if(w->left->color == BLACK && w->right->color == BLACK) {
						w->color = RED;
						x = x->parent;
					}else {
						if(w->left->color == BLACK) {
							w->right->color = BLACK;
							w->color = RED;
							left_rotate(w);
							w = x->parent->left;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->left->color = BLACK;
						right_rotate(x->parent);
						x = root;
					}
				}
			}
			x->color = BLACK;
		}

		// função que pegar o menor valor de uma respectiva sub arvore, é utiliza na função delete
		Node<K, V> *minimum(Node<K, V> *node) {
			while(node->left != nil) {
				node = node->left;
			}
			return node;
		}

		// limpa todos os nos de uma subarvore passada como parametro
		void clear(Node<K, V> *r) {
			Node<K, V> *n = r;
			stack<Node<K, V>*> stack;
		    if(n != nil) {
		    	stack.push(n);
		    }
		    while(!stack.empty()) {
		        Node<K, V> *node = stack.top();
		        if(node->right != nil) {
		            stack.push(node->right);
		        }
		        if(node->left != nil) {
		            stack.push(node->left);
		        }
		        if(node->right == nil && node->left == nil) {
		        	RBdelete(stack.top());
		        	stack.pop();
		        }
		    }
		}

	public:
		
		//construtor para incializar a arvore
		RBTree(K key) {
			nil = new Node<K, V>();
			nil->key = key;
			nil->left = nil->right = nil->parent = nil;
			nil->color = BLACK;
			root = nil;
		}

		//destructor para desalocar espaço da arvore apos fim do programa
		~RBTree (void) {
			clear(root); 
			delete nil;
			nil = nullptr;
			root = nullptr;
		}

		// função visivel para a main inserir um no
		void insert(const K& key, const V& value) {
			Node<K, V> *newNode = new Node<K, V>{};
			newNode->key = key;
			newNode->value = value;
			newNode->left = newNode->right = nil;
			newNode->parent = nil;

			RBinsert(newNode);
		}

		// função visivel para a main deletar um no
		void remove(const K& key) {
			Node<K, V> *p = root;
			while(p != nil && p->key != key) {
				p = (key < p->key) ? p->left : p->right;
			}
			if(p != nil) {
				RBdelete(p);
			}
		}

		// função visivel para a main procurar um no na arvore um no
		bool search(const K& key, V& value) const {
		    Node<K, V> *node = root;
		    while(node != nil) {
		        if(node == nil) {
		        	return false;
		        }else if(node->key == key) {
		            value = node->value;
		            return true;
		        }else if(key < node->key) {
		            node = node->left;
		        }else if(key > node->key) {
		            node = node->right;
		        }
		    }
		    return false;
		}

		// mostra a arvore no sentido pre ordem, Raiz, Esquerda, Direita
		void preorder() const {
		    Node<K, V> *node = root;
		    stack<Node<K, V>*> stack;
		    stack.push(node);
		    while(!stack.empty()) {
		        Node<K, V> *node = stack.top();
		        cout << "key: " << node->key << " color: ";
		        string c;
		        node->color == 1 ? c = "BLACK" : c = "RED";
		        cout << c << endl;
		        stack.pop();
		        if(node->right != nil) {
		            stack.push(node->right);
		        }
		        if(node->left != nil) {
		            stack.push(node->left);
		        }
		    }
		}

		//limpa todos os nos da arvore
		void clearAll() {
			clear(root);	
		}

		//mostra a altura negra da arvore 
		int blackheight() const {
			Node<K, V> *node = root;
			int count=0;
			if(node != nil) {
				count = 1;
			}
			while(node->right != nil) {
				if(node->right->color == BLACK) {
					count++;
				}
				node = node->right;
			}
			return count;
		}

		//verifica se a arvore esta vazia ou cheia
		bool empty() const {
			Node<K, V> *node = root;
			if(node == nil) {
				return true;
			}
			return false;
		}
};
#endif