#ifndef BNODE_H
#define BNODE_H
#include <iostream>

class Bnode {
private:
    int *key;       // vetor de chaves
    int d;          // grau minimo
    Bnode **c;      // vetor de ponteiros para filhos
    int n;          // numero atual de chaves
    bool leaf;      // true se o noh eh uma folha, false caso contrario
public:
    // Construtor
    Bnode(int d, bool leaf);

    // Destrutor
    ~Bnode();

    // Funcao que busca a chave k na subarvore 
    // enraizada neste no. Se a chave existir, retorna
    // o ponteiro para o no e o valor do indice da chave
    // na variavel index. Caso contrario, retorna nullptr
    // e o valor de index eh indefinido.
    Bnode *search(int k, int& index);

    // Imprime todas as chaves do no em ordem crescente
    // Incompleto
    void printKeys();

    // Funcao que divide o filho c[i] deste no.  
    // O no apontado por c[i] deve estar cheio 
    // quando esta funcao eh chamada.
    void splitChild(int i);

    // Funcao que insere uma nova chave na subarvore 
    // enraizada neste no. Supomos que o no nao esta 
    // cheio quando esta funcao eh chamada 
    void insertNonFull(int k);

    // Faz Btree uma classe amiga desta, para que possamos acessar
    // os membros privados desta classe nas funções de Btree. 
    friend class Btree; 
};

Bnode::Bnode(int d, bool leaf) {
    this->d = d;            // grau minimo do noh
    this->leaf = leaf;      // indica se noh eh folha
    n = 0;                  // no inicio o noh nao tem chaves
    key = new int[2*d - 1]; // o noh pode ter no maximo 2d-1 chaves
    c = new Bnode*[2*d];    // o noh pode ter no maximo 2d filhos
}

Bnode::~Bnode() {
    std::cout << "No removido com chaves: " << std::endl;
    for(int i = 0; i < n; i++) std::cout << key[i] << " ";
    std::cout << std::endl;
    delete[] key;
    delete[] c;
}

Bnode *Bnode::search(int k, int& index) {
    // Encontra a primeira chave maior ou igual a k
    int i = 0;
    while(i <= n-1 && k > key[i])
        i++;
    
    // A chave foi encontrada neste no.
    if(i <= n-1 && k == key[i]) {
        index = i;
        return this;
    }
    // A chave nao foi encontrada neste no e ele eh folha.
    else if(leaf == true)
        return nullptr;
    // Desce para o filho apropriado
    else 
        return c[i]->search(k, index);
}

 
void Bnode::printKeys() { 
    int i;
    for(i=0; i<n; i++) {
    	if(leaf == false)
    		c[i]->printKeys();
    	std::cout << " " << key[i];
    }

    if(leaf == false)
    	c[i]->printKeys();
} 


void Bnode::splitChild(int i) {
    // y eh o filho deste no que sera dividido
    Bnode *y = this->c[i];

    // Aloca memoria para um novo no que armazenara as
    // d-1 maiores chaves de y
    Bnode *z = new Bnode(d, y->leaf);
    z->n = d-1;

    // Copia as ultimas d-1 chaves de y para z
    for(int j = 0; j < d-1; j++)
        z->key[j] = y->key[j+d];

    // Copia os ultimos d filhos de y para z
    if(y->leaf == false) {
        for(int j = 0; j < d; j++)
            z->c[j] = y->c[j+d];
    }

    // Atualiza o numero de chaves de y
    y->n = d-1;

    // Como este no tera um novo filho, criamos
    // espaco para o ponteiro para o novo filho
    for(int j = n; j >= i+1; j--)
        c[j+1] = c[j];

    // Faz c[i+1] apontar para z
    c[i+1] = z;

    // Move a chave mediana de y para este no.
    // Encontra a posicao da nova chave e move todas
    // as chaves maiores uma posicao para a frente
    for(int j = n-1; j >= i; j--)
        key[j+1] = key[j];

    // Copia a chave mediana de y para este no.
    key[i] = y->key[d-1];

    // Incrementa o numero de chaves deste no.
    n = n + 1;
}

void Bnode::insertNonFull(int k) {
    // Inicia i com o indice da chave mais a direita
    int i = n-1;

    // Se este no eh folha
    if(leaf == true) {
        // Este loop move as chaves uma posicao para 
        // a direita ate achar a posicao correta da nova chave.
        while(i >= 0 && k < key[i]) {
            key[i+1] = key[i];
            i--;
        }
        // Insere a nova chave na posicao correta
        key[i+1] = k;
        n = n+1;
    }
    // Se este no nao eh folha
    else {
        // Encontra o filho que tera a nova chave
        while(i >= 0 && k < key[i]) 
            i--;
        
        i++;

        // Checa se o filho encontrado esta cheio
        if(c[i]->n == 2*d-1) {
            // Se o filho c[i] deste no estiver cheio, divida-o
            splitChild(i);

            // Depois de dividir, a chave do meio de c[i] sobe
            // para este no e c[i] eh dividido  em dois. Agora,
            // devemos decidir qual das duas metades tera a 
            // nova chave
            if(k > key[i])
                i++;
        }
        c[i]->insertNonFull(k);
    }

}

#endif