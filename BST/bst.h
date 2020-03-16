/**
 * --- bst.h -------------------------------------------------
 * Header file with public interface for a Binary Search Tree.
 * March 4, 2020
 */
#ifndef BST_H
#define BST_H
#include "item.h"

/**
 * Tipo Node. Um struct que possui campos
 * para a chave, para o valor, e ponteiros
 * para o filho esquerdo e direito. */
struct Node;

/**
 * Recebe um ponteiro para um no da arvore e retorna 
 * a chave contida neste no */
Tkey bst_getKey(Node *node);

/**
 * Recebe um ponteiro para um no da arvore e retorna 
 * o valor contido neste no */
Tvalue bst_getValue(Node *node);

/**
 * Recebe o ponteiro para a raiz da arvore e 
 * para a chave a ser pesquisada. Retorna o ponteiro
 * para o no se a chave for encontrada; ou retorna nullptr
 * caso contrário */
Node *bst_search(Node *node, Tkey key);

/**
 * Recebe um ponteiro para a raiz da arvore, uma chave e um valor.
 * Se a chave nao existir, insere um novo no com o par (chave,valor)
 * Se a chave existir, nao insere nada.
 * Retorna um ponteiro para a raiz da arvore modificada. */
Node *bst_insert(Node *node, Tkey key, Tvalue value);

/**
 * Recebe um ponteiro para a raiz da arvore e 
 * Percorre os nos da arvore em pre-ordem e imprime na 
 * tela os pares (chave, valor) */
void bst_preorder(Node *node);

/**
 * Recebe um ponteiro para a raiz da arvore e 
 * recebe um ponteiro f para uma funcao. 
 * Percorre os nos da arvore em pre-ordem fazendo o que 
 * a funcao f disser para fazer. */
void bst_preorder(Node *node, void f(Node*));

/**
 * Recebe um ponteiro para a raiz da arvore e 
 * Percorre os nos da arvore em ordem simetrica (inorder) e imprime na 
 * tela os pares (chave, valor) */
void bst_inorder(Node *node);

/**
 * Recebe um ponteiro para a raiz da arvore e 
 * Percorre os nos da arvore em pós-ordem e imprime na 
 * tela os pares (chave, valor) */
void bst_postorder(Node *node);

/**
 * Recebe um ponteiro para a raiz da arvore e retorna a 
 * altura da arvore. */
int bst_height(Node *node);

/**
 * Recebe um ponteiro para a raiz da arvore.
 * Retorna true se a arvore estiver vazia e false, caso
 * contrario. */
bool bst_empty(Node* node);

/**
 * Recebe um ponteiro para a raiz da arvore e libera todos
 * os nos, deixando a arvore vazia. Retorna nullptr. */
Node *bst_clear(Node *node);

/**
 * Recebe um ponteiro para a raiz da arvore e uma chave.
 * Se existir um no com essa chave, remove o no.
 * Se nao existir, nada acontece.
 * Retorna um ponteiro para a raiz da arvore modificada. */
Node *bst_remove(Node *node, Tkey key);

/**
 * Recebe um ponteiro para a raiz da arvore e 
 * retorna um ponteiro para o no que contem a menor chave */
Node *bst_minimum(Node *node);

/**
 * Recebe um ponteiro para a raiz da arvore e 
 * retorna um ponteiro para o no que contem a maior chave */
Node *bst_maximum(Node *node);

/**
 * Recebe como parametro um ponteiro para a raiz da arvore 
 * e um ponteiro para um no x.
 * Retorna o ponteiro para o no cuja chave eh sucessora
 * da chave contida em x. */
Node* bst_successor(Node* root, Node *x);

/**
 * Recebe como parametro um ponteiro para a raiz da arvore 
 * e um ponteiro para um no x.
 * Retorna o ponteiro para o no cuja chave eh antecessora
 * da chave contida em x. */
Node* bst_predecessor(Node* root, Node *x);


#endif