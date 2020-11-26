/*
Samuel Evangelista, Guilherme Willian
*/


#include <bits/stdc++.h>
#include "graph.h"

#define Direcionado true
#define Nao_direcionado false

using namespace std;

/*
Para conseguirmos solucionar essa questão sem PD, ou uma PD(mascarada) tivemos que criar uma struct para guardar as flags
de status de cada nivel da busca em profundidade, assim poderiamos passar as alterações e possibilidades para cima da recursão
basicamente, fizemos uma busca onde são aceito a possibilidade de termos dois casos, caso em pegar o atual e nao pegar atual
caso atual seje pegue, não podemos pegar o seguinte a ele, e assim sucessivamente. O algoritmo guloso não tem a solução otima
desse algoritmo, por isso tentamos implementar de forma a uma PD(programação dinâmica), salvando status anteriores para termos
a melhor solução
*/
typedef struct {	
	int rsl, rsnl; // resultado_se_livre, resultado_se_nao_livre
	bool psl, psnl; // possibilidade_se_livre, possibilidade_se_nao_livre
}dfsResult;


//refazer caso1 caso escolha 
dfsResult DFS(int v, Grafo *g){
	int caso1 = 1, caso2 = 0;
	bool caso1p = false, caso2p = false; //case1p = true, se algum dos filhos de v possuir mais de uma possibilidade caso nao livre	
										 // se pegarmos o nó atual, teremos mais de uma possiblidade para ele 
	for(auto u : g->adjList[v]) {
		dfsResult ansu = DFS(u, g);

		caso1 += ansu.rsnl;
		caso1p = caso1p || ansu.psnl; // seleciona o no atual, no debaixos nao estao livres
		caso2 += ansu.rsl;
		caso2p = caso2p || ansu.psl; // nao seleciona o no atual, nos debaixo livres
	}
	dfsResult ansv;
	if(caso1 > caso2) { // caso em que pegando o nó atual é maior
		ansv.rsl = caso1;
		ansv.psl = caso1p;
	}
	if(caso2 > caso1) { // caso em que não pegando o nó atual é maior
		ansv.rsl = caso2;
		ansv.psl = caso2p;
	}
	if(caso1 == caso2) { // caso em que tanto faz se pegar o nó atual ou não, logo temos mais de uma opção, entao a psl = true
		ansv.rsl = caso2;
		ansv.psl = true;
	}
	ansv.rsnl = caso2;  // caso em que o nó atual não é pego 
	ansv.psnl = caso2p;
	return ansv;
}

int main() {
	Grafo *g; // grafo
    int vertices, origem, destino; // auxiliares do grafo
    map<string, int> inp; //map auxiliar para trator string para inteiros
    map<string, int>::iterator it;

	ifstream in; // entrada
	ofstream out; // saida	
	in.open("../in.txt");
	out.open("../out.txt");
	
	while(true) {
		int aux=1;
		string line, fst, snd;
		getline(in, line, '\n'); // pegar os vertices
		vertices = stoi(line);
		g = new Grafo(vertices, Direcionado); // criar o grafo
		if(vertices==0) {
			return 0;
		}
		getline(in, line, '\n'); // pegar o chefe e criar o chefe
		inp.insert(pair<string, int>(line, aux));// criar chefe com o primeiro id
		aux++;
		for(int i=0; i<(vertices-1); i++) {
        	getline(in, line, '\n');
        	stringstream s(line);
        	s >> fst >> snd; // pegando chefe e funcionario no fluxo
        	it = inp.find(fst);
        	if(it == inp.end()) {
        		inp.insert(pair<string, int>(fst, aux)); // criar o primeiro funcionario, partimos que todo o chefe é anteriormente criado
        		aux++;
        	}
        	origem = inp[snd]; // origem = chefe = snd
        	destino = inp[fst]; // destino = funcionario = fst
        	g->addAresta(origem, destino); //crio a aresta no grafo
    	}
    	dfsResult ans; //crio a struct de flags para pegar o resultado da DFS
		ans = DFS(1, g); // chamo a DFS
		out << ans.rsl << " " << (ans.psl ? "NAO":"SIM") << endl; // Resultado
		delete g;
    	inp.clear();
	}
}