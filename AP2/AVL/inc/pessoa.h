#ifndef PESSOA_H
#define PESSOA_H

#include <bits/stdc++.h>

using std::string;
 
class Pessoa {
public:
	string Cpf;
	string Nome;
	string SNome;
	string Data;
	string Cidade;
	
	/* Constructor */
	Pessoa( string Cpf, string Nome, string SNome, string Data, string Cidade )  {
		this->Cpf = Cpf;
		this->Nome = Nome;
		this->SNome = SNome;
		this->Data = Data;
		this->Cidade = Cidade;
	};
};

#endif
