#include <stdio.h>
#include <iostream>
#include <cstring>
#include <locale>
#include "costante.h"
#include "produto.h"
using namespace std;
int main()
{
   string nome;
	int opcao;
	do {
		cout << "Sistema" << endl;
		cout << CADASTRAR << " - Cadastar Veiculo" << endl;
		cout << LISTAR << "- Listar Veiculo" << endl;
		cout << PESQUISAR << "- Pesquisar Veiculo Utilização" << endl;
		cout << LISTAR3 << "- Listar Revisão" << endl;
		cout << "9 - Sair" << endl;
		cout << "Entre com Opcao" << endl;
		cin >> opcao;
		switch (opcao)
		{
		case CADASTRAR: cadastrarTexto(produto, posProduto);break;
		case LISTAR: listarTexto(0, produto, posProduto);break;
		case PESQUISAR :
		    cout << "Entre com o veiculo a ser pesquisado" << endl;
	        cin.ignore();
	        getline(cin, nome);
	        char vetorPesquisa[LARGURA];
	        strcpy(vetorPesquisa, nome.c_str());
	        pesquisarTexto(0,produto,posProduto,vetorPesquisa);
		default:
			break;
		case LISTAR3: listarRevisao (0, produto, posProduto); break;
		}
	} while (opcao >= 1 && opcao <= 4);
	system("pause");
	return 0;
}
