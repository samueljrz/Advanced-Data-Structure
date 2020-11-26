#include <iostream>
#include "bnode.h"
using namespace std;

class Btree {
private:
    // ponteiro para o no raiz
    Bnode *root; 
    // grau minimo do no
    int d; 
protected:
    // libera todos os nos e deixa arvore vazia
    Bnode *clear(Bnode *node);
public:
    // Construtor
    Btree(int d);
    // Destrutor
    ~Btree();
    // Insere uma chave na arvore 
    void insert(int k);
    // Remove uma chave na arvore
    void remove(int k);
    // Busca uma chave k na arvore
    bool search(int k);
    // Imprime as chaves da arvore
    void printKeys();
    // retorna o antecessor de uma chave
    void predecessor(int pos, Bnode *aux, bool *val);
    // retorna posiçaõ do no
    int searchPos(int k, Bnode *node);   
    // verifica se a chave esta naquele no
    bool here(int k, Bnode *node); 
    //aux remove
    void removeaux(int k, Bnode *r, bool *val);
    //restaurar arvore
    void reconstitute(Bnode *aux, int pos, bool *val);
    //aux
    void insereNaPagina(Bnode *p, int k, Bnode *aux);
};

Btree::Btree(int d) {
    this->d = d;
    root = nullptr;
}

bool Btree::search(int k) {
    if(root != nullptr) {
        int i;
        Bnode *node = root->search(k,i);
        return (node != nullptr);
    }
    else return false;
}

int Btree::searchPos(int k, Bnode *node) {
    int pos = 1;
    while (pos < node->n && k > node->key[pos-1])
        pos++;
    return pos;
}

bool Btree::here(int k, Bnode *node) {
    for(int i=0; i<node->n; i++) {
        if(k == node->key[i]) {
            return true;
        }
    }
    return false;
}

void Btree::predecessor(int pos, Bnode *aux, bool *val) {
    if(aux->c[aux->n] != nullptr) {
        predecessor(pos, aux->c[aux->n], val);
        if(*val) {
            reconstitute(aux, aux->n, val);
        }
        return;
    }
    root->key[pos-1] = aux->key[aux->n-1];
    aux->n--;
    *val = aux->n < aux->d ? true : false;
}

void Btree::insert(int k) {
    // Arvore vazia
    if(root == nullptr) {
        root = new Bnode(d, true); // Aloca memoria
        root->key[0] = k; // Insere a chave
        root->n = 1; // Atualiza o numero de chaves
    }
    // Arvore nao-vazia
    else { 
        // Se a raiz estiver cheia
        if(root->n == 2*d-1) {
            // Aloca memoria para a nova raiz
            Bnode *s = new Bnode(d, false);
            
            // Faz a raiz antiga ser filha da nova raiz
            s->c[0] = root;

            // Divide a raiz antiga e move uma chave para a nova raiz s
            s->splitChild(0);

            // A nova raiz tem dois filhos agora. 
            // Decida qual dos dois filhos vai receber
            // a nova chave
            int i = 0;
            if(s->key[0] < k)
                i++;
            s->c[i]->insertNonFull(k);

            // Muda a raiz para s
            root = s;
        }
        else {
            root->insertNonFull(k);
        }
        
    }
}

void Btree::insereNaPagina(Bnode *p, int key, Bnode *aux) {
    int k;
    bool ver;
    k = p->n;
    ver = k > 0 ? true : false;
    while(ver) {
        if(key >= p->key[k-1]) {
            ver = false;
            break;
        }
        p->key[k] = p->key[k-1];
        p->c[k+1] = p->c[k];
        k--;
        if(k < 1) {
            ver = false;
        }
    }
    p->key[k] = key;
    p->c[k+1] = aux;
    p->n++;
} 

void Btree::reconstitute(Bnode *aux, int pos, bool *val) {
    Bnode *temp;
    int auxtemp;

    if(pos < aux->n) {
        temp = aux->c[pos+1];
        auxtemp = (temp->n - temp->d + 1) / 2;
        root->key[root->n] = aux->key[pos];
        root->c[root->n+1] = temp->c[0];
        root->n++;
        if(auxtemp > 0) {
            for(int i=1; i<auxtemp; i++) {
                insereNaPagina(root, temp->key[i-1], temp->c[i]);
            }
            aux->key[pos] = temp->key[auxtemp-1];
            temp->n -= auxtemp;
            for(int i=0; i<temp->n; i++) {
                temp->key[i] = temp->key[i+auxtemp];
            }
            for(int i=0; i<=temp->n; i++) {
                temp->c[i] = temp->c[i+auxtemp];
            }
            *val = false;
        }else {
            for(int i=1; i<=aux->d; i++) {
                insereNaPagina(root, temp->key[i-1], temp->c[i]);
            }
            free(temp);
            for(int i=pos+1; i<aux->n; i++) {
                aux->key[i-1] = aux->key[i];
                aux->c[i] = aux->c[i+1];
            }
            aux->n--;
            if(aux->n >= aux->d) {
                *val = false;
            }
        }
    }else {
        temp = aux->c[pos-1];
        auxtemp = (temp->n - temp->d + 1) / 2;
        for(int i=root->n; i>=1; i++) {
            root->key[i] = root->key[i-1];
        } 
        root->key[0] = aux->key[pos-1];
        for(int i=root->n; i>=0; i++) {
            root->c[i+1] = root->c[i];
        }
        root->n++;
        if(auxtemp > 0) {
            for (int i=1; i<auxtemp; i++) {
                insereNaPagina(root, temp->key[temp->n-i], temp->c[temp->n-i+1]);
            }
            root->c[0] = temp->c[temp->n - auxtemp + 1];
            aux->key[pos-1] = temp->key[temp->n-auxtemp];
            temp->n -= auxtemp;
            *val = false;
        }else {
            for (int i=1; i<=aux->d; i++) {
                insereNaPagina(temp, root->key[i-1], root->c[i]);
            }
            free(temp);
            aux->n--;
            if(aux->n >= aux->d) {
                *val = false;
            }
        }
    }
}

void Btree::removeaux(int k, Bnode *r, bool *val) {
    int pos;
    Bnode *auxc;
    int *auxkey;
    if(root == nullptr) {
        *val = false;
        cout << "Chave nao encontrada" << endl;
        return;
    }
    auxc = root;
    pos = searchPos(k, auxc);
    cout << pos << endl;
    if(k == auxc->key[pos-1]) {
        if(auxc->leaf) {
            auxc->n--;
            *val = auxc->n < auxc->d ? true : false;
            for (int i=pos; i<=auxc->n; i++) {
                auxc->key[i-1] = auxc->key[i];
                auxc->c[i] = auxc->c[i+1];
            }
            return;
        }
        predecessor(pos, auxc->c[pos-1], val);
        if(*val) { 
            reconstitute(auxc->c[pos-1], pos-1, val);
        }   
        return;
    }
    if(k > auxc->key[pos-1]) {
        pos++;
    }
    removeaux(k, auxc->c[pos-1], val);
    if(*val) {
        reconstitute(auxc->c[pos-1], pos-1, val);
    }
}

void Btree::remove(int k) {
    bool val;
    Bnode *aux;
    removeaux(k, root, &val);
    if(val and root->n == 0) {
        aux = root;
        root = aux->c[0];
        free(aux);
    }
}

void Btree::printKeys() {
    if(root != nullptr)
        root->printKeys();
}

Btree::~Btree() {
    root = clear(root);
}


Bnode *Btree::clear(Bnode *node) {
    if(node != nullptr) {
        if(node->leaf == true) {
            delete node;
            return nullptr;
        }
        else {
            for(int i = 0; i <= node->n; i++) {
                node->c[i] = clear(node->c[i]);
            }
            delete node;
            return nullptr;
        }
    }
}